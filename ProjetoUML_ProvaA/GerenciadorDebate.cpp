#include "GerenciadorDebate.hpp"
#include "Facade.hpp"
#include "FasePergunta.hpp"
#include "FaseResposta.hpp"
#include "FaseReplica.hpp"
#include "FaseTreplica.hpp"
#include "FaseDefesaDR.hpp"
#include "FimDaRodada.hpp"
#include <iostream>
#include <random>
#include <stdexcept>
#include <thread>
#include <chrono>

GerenciadorDebate::GerenciadorDebate() {
    this->faseAtual    = "Inicial";
    this->inquiridor   = nullptr;
    this->inquirido    = nullptr;
    this->candidatoAtual = nullptr;
    this->drBloqueado  = false;
    // Estado inicial do padrão State
    this->subFaseAtual = new FasePergunta();
}

GerenciadorDebate::~GerenciadorDebate() {
    delete subFaseAtual;
}

// ─── State ────────────────────────────────────────────────────────────────────

void GerenciadorDebate::setSubFase(SubFase* novaFase) {
    delete subFaseAtual;        // libera estado anterior
    subFaseAtual = novaFase;
    this->registrarAcao("SubFase alterada para: " + novaFase->getFase());
}

// ─── Candidatos ───────────────────────────────────────────────────────────────

void GerenciadorDebate::setCandidatos(const vector<CandidatoConcreto*>& novosCandidatos) {
    this->candidatos           = novosCandidatos;
    this->inquiridoresRestantes = novosCandidatos;

    this->registrarAcao("Lista de candidatos atualizada com " +
                        to_string(this->candidatos.size()) + " participantes.");
    cout << "Lista de candidatos atualizada com "
         << this->candidatos.size() << " participantes." << endl;

    cout << "O nome dos respectivos candidatos sao: " << endl;
    for (auto* c : this->candidatos) {
        cout << "- " << c->getNome() << endl;
        this->registrarAcao("- " + c->getNome());
    }
}

void GerenciadorDebate::sortearInquiridor() {
    if (inquiridoresRestantes.empty()) {
        cout << "[Gerenciador]: Todos ja foram inquiridores!" << endl;
        return;
    }

    mt19937 gen(random_device{}());
    uniform_int_distribution<> dist(0, inquiridoresRestantes.size() - 1);
    int idx = dist(gen);

    this->inquiridor     = inquiridoresRestantes[idx];
    this->nomeInquiridor = this->inquiridor->getNome();
    inquiridoresRestantes.erase(inquiridoresRestantes.begin() + idx);

    cout << "[Sorteio]: Inquiridor da rodada: " << this->nomeInquiridor << endl;
    this->registrarAcao("Inquiridor sorteado: " + this->nomeInquiridor);
}

void GerenciadorDebate::definirInquirido(int id) {
    CandidatoConcreto* escolhido = nullptr;

    if (id >= 0 && id < static_cast<int>(candidatos.size()))
        escolhido = candidatos[id];

    // Invalido ou coincide com o inquiridor → sorteia outro
    if (escolhido == nullptr ||
        (inquiridor != nullptr && escolhido->getNome() == inquiridor->getNome())) {

        cout << "[Aviso]: ID invalido ou coincide com o Inquiridor. Sorteando novo inquirido..." << endl;

        mt19937 gen(random_device{}());
        uniform_int_distribution<> dist(0, candidatos.size() - 1);
        do {
            escolhido = candidatos[dist(gen)];
        } while (inquiridor != nullptr && escolhido->getNome() == inquiridor->getNome());
    }

    this->inquirido     = escolhido;
    this->nomeInquirido = this->inquirido->getNome();

    cout << "[Gerenciador]: Inquirido definido: " << this->nomeInquirido << endl;
    this->registrarAcao("Inquirido definido: " + this->nomeInquirido);
}

void GerenciadorDebate::iniciarFase(int tempo) {
    this->faseAtual = "Fase Ativa";
    this->cronometro.iniciar(tempo);
    this->registrarAcao("Nova fase de debate iniciada!");
    cout << "Uma nova fase de debate foi iniciada!" << endl;
}

// ─── Observer ─────────────────────────────────────────────────────────────────

void GerenciadorDebate::registrarObservador(Observador* obs) {
    if (obs != nullptr)
        this->observadores.push_back(obs);
}

void GerenciadorDebate::notificarTodos(string mensagem) {
    if (this->candidatoAtual == nullptr) return;

    int idAtivo = -1;
    for (size_t i = 0; i < candidatos.size(); i++) {
        if (candidatos[i] == this->candidatoAtual) {
            idAtivo = static_cast<int>(i);
            break;
        }
    }

    for (Observador* obs : observadores) {
        if (obs->getCandidatoId() == idAtivo)
            obs->atualizar(mensagem);
    }
}

// ─── Candidato atual ──────────────────────────────────────────────────────────
 
void GerenciadorDebate::setCandidatoAtual(
    Candidato* c
) {
    candidatoAtual = c;

    if(c != nullptr)
        notificarTodos(
            "O candidato atual mudou e começou a falar."
        );
}

void GerenciadorDebate::setCandidatoAtualPorNome(const string& nome) {
    for (auto* c : candidatos) {
        if (c->getNome() == nome) {
            setCandidatoAtual(c);
            return;
        }
    }
}

// ─── Direito de Resposta ──────────────────────────────────────────────────────

void GerenciadorDebate::solicitarDRPorId(int candidatoId) {
    if (candidatoId < 0 || candidatoId >= static_cast<int>(candidatos.size())) {
        cout << "[DR]: ID " << candidatoId << " invalido. Solicitacao ignorada." << endl;
        return;
    }
    solicitarDR(candidatos[candidatoId]);
}

void GerenciadorDebate::solicitarDR(Candidato* candidato) {
    if (drBloqueado) {
        cout << "[DR]: Solicitacao de DR de " << candidato->getNome()
             << " BLOQUEADA — DRs estao ocorrendo agora." << endl;
        this->registrarAcao("DR bloqueado para: " + candidato->getNome());
        return;
    }

    // Evita duplicatas na fila
    queue<Candidato*> copia = filaDR;
    while (!copia.empty()) {
        if (copia.front() == candidato) {
            cout << "[DR]: " << candidato->getNome()
                 << " ja esta na fila de DR." << endl;
            return;
        }
        copia.pop();
    }

    filaDR.push(candidato);
    cout << "[DR]: " << candidato->getNome()
         << " solicitou Direito de Resposta. Posicao na fila: "
         << filaDR.size() << endl;
    this->registrarAcao("DR solicitado por: " + candidato->getNome());
}

void GerenciadorDebate::simularPedidosDR() {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(1,100);

    for(auto* candidato : candidatos)
    {

        // ===== SORTEIO DE DR =====
        int chance = dist(gen);

        if(chance <= 15) // 15% de chance
        {
            cout << "\n[SIMULACAO] "
                 << candidato->getNome()
                 << " decidiu pedir DR."
                 << endl;

            candidato->getMicrofone()
                     .pressionarBotaoDR(this);
        }
    }
}

// ─── Fluxo principal ──────────────────────────────────────────────────────────

void GerenciadorDebate::proximaAcao(int tempoPorEtapa) {
    if (inquiridor == nullptr || inquirido == nullptr) {
        cout << "[Erro]: Defina inquiridor e inquirido antes de avancar." << endl;
        return;
    }
    // Delega para o estado atual — padrão State em ação
    subFaseAtual->processarFase(this, tempoPorEtapa);
}

void GerenciadorDebate::executarRodadaAutomatica(int tempoPorEtapa) {
    if (inquiridor == nullptr || inquirido == nullptr) {
        cout << "[Erro]: Defina o inquiridor e o inquirido antes de iniciar o fluxo!" << endl;
        return;
    }

    // Ciclo: PERGUNTA → RESPOSTA → REPLICA → TREPLICA
    for (int i = 0; i < 4; i++) {

    this->proximaAcao(tempoPorEtapa);

    this->cronometro.iniciar(tempoPorEtapa);

    for(int segundo = 0;
        segundo < tempoPorEtapa;
        segundo++)
    {
        simularPedidosDR();

        this_thread::sleep_for(
            chrono::seconds(1)
        );
    }

    cout << "\n[Tempo Esgotado!] Fim do tempo para esta etapa.\n" << endl;
    }

    // Após a TREPLICA: FaseDefesaDR (se houver DR) ou FimDaRodada
    this->proximaAcao(tempoPorEtapa);
}

// ─── Utilitários ─────────────────────────────────────────────────────────────

void GerenciadorDebate::registrarAcao(string acao) {
    Facade::getInstance().getLogger().registrar("[GerenciadorDebate] " + acao);
}

void GerenciadorDebate::resetarRodada() {
    this->inquiridor     = nullptr;
    this->inquirido      = nullptr;
    this->nomeInquiridor = "";
    this->nomeInquirido  = "";
}