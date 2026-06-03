#include "GerenciadorDebate.hpp"
#include "Facade.hpp"
#include <iostream>
#include <random>    
#include <stdexcept> 
#include <thread> 
#include <chrono> 

GerenciadorDebate::GerenciadorDebate() {
    this->faseAtual = "Inicial";
    this->inquiridor = nullptr;
    this->inquirido = nullptr;
    this->candidatoAtual = nullptr;
}

void GerenciadorDebate::setCandidatos(const vector<CandidatoConcreto*>& novosCandidatos) {
    this->candidatos = novosCandidatos;
    this->inquiridoresRestantes = novosCandidatos; 

    this->registrarAcao("Lista de candidatos atualizada com " + to_string(this->candidatos.size()) + " participantes.");
    cout << ("Lista de candidatos atualizada com " + to_string(this->candidatos.size()) + " participantes.") << endl;

    this->registrarAcao("O nome dos respectivos candidatos são: ");
    cout << ("O nome dos respectivos candidatos são: ") << endl;

    for (size_t i = 0; i < this->candidatos.size(); i++) {
        string nomeDoCandidato = this->candidatos[i]->getNome(); 
        this->registrarAcao("- " + nomeDoCandidato);
        cout << ("- " + nomeDoCandidato) << endl;
    }
}

void GerenciadorDebate::sortearInquiridor() {
    if (inquiridoresRestantes.empty()) {
        std::cout << "[Gerenciador]: Todos já foram inquiridores!" << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, inquiridoresRestantes.size() - 1);

    int indiceSorteado = distrib(gen);
    this->inquiridor = inquiridoresRestantes[indiceSorteado];
    
    this->nomeInquiridor = this->inquiridor->getNome();

    inquiridoresRestantes.erase(inquiridoresRestantes.begin() + indiceSorteado);

    std::cout << "[Sorteio]: Inquiridor da rodada: " << this->nomeInquiridor << std::endl;
    this->registrarAcao("Inquiridor sorteado: " + this->nomeInquiridor);
}

void GerenciadorDebate::definirInquirido(int id) {
    CandidatoConcreto* candidatoEscolhido = nullptr;

    if (id >= 0 && id < static_cast<int>(candidatos.size())) {
        candidatoEscolhido = candidatos[id];
    }

    if (candidatoEscolhido == nullptr || (this->inquiridor != nullptr && candidatoEscolhido->getNome() == this->inquiridor->getNome())) {
        
        std::cout << "[Aviso]: O ID fornecido era invalido ou coincidia com o Inquiridor. Realizando nova escolha do inquirido..." << std::endl;
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, candidatos.size() - 1);

        do {
            int indiceSorteado = distrib(gen);
            candidatoEscolhido = candidatos[indiceSorteado];
        } while (this->inquiridor != nullptr && candidatoEscolhido->getNome() == this->inquiridor->getNome());
    }

    this->inquirido = candidatoEscolhido;
    this->nomeInquirido = this->inquirido->getNome();

    std::cout << "[Gerenciador]: Inquirido definido com sucesso: " << this->nomeInquirido << std::endl;
    this->registrarAcao("Inquirido definido com sucesso: " + this->nomeInquirido);
}

// Inicializa o tempo da fase activa
void GerenciadorDebate::iniciarFase(int tempo) {
    this->faseAtual = "Fase Ativa";
    this->cronometro.iniciar(tempo);
    this->registrarAcao("Uma nova fase de debate foi iniciada!");
    cout << ("Uma nova fase de debate foi iniciada!") << endl;
}

// Repassa com segurança para o Logger da Facade
void GerenciadorDebate::registrarAcao(string acao) {
    Facade::getInstance().getLogger().registrar("[GerenciadorDebate] " + acao);
}

void GerenciadorDebate::registrarObservador(Observador* obs) {
    if (obs != nullptr) {
        this->observadores.push_back(obs);
    }
}

void GerenciadorDebate::notificarTodos(string mensagem) {
    if (this->candidatoAtual == nullptr) return;

    int idCandidatoAtivo = -1;
    for (size_t i = 0; i < candidatos.size(); i++) {
        if (candidatos[i] == this->candidatoAtual) {
            idCandidatoAtivo = i; 
            break;
        }
    }

    for (Observador* obs : observadores) {
        if (obs->getCandidatoId() == idCandidatoAtivo) {
            obs->atualizar(mensagem);
        }
    }
}

void GerenciadorDebate::setCandidatoAtual(CandidatoConcreto* c) {
    this->candidatoAtual = c;
    if (this->candidatoAtual != nullptr) {
        string msg = "O candidato atual mudou e começou a falar no debate.";
        notificarTodos(msg);
    }
}

void GerenciadorDebate::proximaAcao() {
    if (this->inquiridor == nullptr || this->inquirido == nullptr) {
        std::cout << "[Erro]: Não é possível avançar. Certifique-se de que o inquiridor e inquirido foram definidos." << std::endl;
        return;
    }

    switch (subFaseAtual) {
        case PERGUNTA:
            std::cout << "\n==========================================" << std::endl;
            std::cout << "--- ETAPA: PERGUNTA ---" << std::endl;
            std::cout << ">> " << this->inquiridor->getNome() << " está fazendo a pergunta." << std::endl;
            std::cout << "==========================================" << std::endl;
            
            this->setCandidatoAtual(this->inquiridor); 
            this->registrarAcao("Etapa mudada para PERGUNTA. Falando: " + this->inquiridor->getNome());
            subFaseAtual = RESPOSTA; 
            break;

        case RESPOSTA:
            std::cout << "\n==========================================" << std::endl;
            std::cout << "--- ETAPA: RESPOSTA ---" << std::endl;
            std::cout << ">> " << this->inquirido->getNome() << " está respondendo." << std::endl;
            std::cout << "==========================================" << std::endl;
            
            this->setCandidatoAtual(this->inquirido); 
            this->registrarAcao("Etapa mudada para RESPOSTA. Falando: " + this->inquirido->getNome());
            subFaseAtual = REPLICA;
            break;

        case REPLICA:
            std::cout << "\n==========================================" << std::endl;
            std::cout << "--- ETAPA: RÉPLICA ---" << std::endl;
            std::cout << ">> " << this->inquiridor->getNome() << " está na réplica." << std::endl;
            std::cout << "==========================================" << std::endl;
            
            this->setCandidatoAtual(this->inquiridor); 
            this->registrarAcao("Etapa mudada para RÉPLICA. Falando: " + this->inquiridor->getNome());
            subFaseAtual = TREPLICA;
            break;

        case TREPLICA:
            std::cout << "\n==========================================" << std::endl;
            std::cout << "--- ETAPA: TRÉPLICA ---" << std::endl;
            std::cout << ">> " << this->inquirido->getNome() << " está na tréplica." << std::endl;
            std::cout << "==========================================" << std::endl;
            
            this->setCandidatoAtual(this->inquirido); 
            this->registrarAcao("Etapa mudada para TRÉPLICA. Falando: " + this->inquirido->getNome());
            subFaseAtual = FIM_DA_RODADA;
            break;

        case FIM_DA_RODADA:
            std::cout << "\n[Gerenciador]: Rodada encerrada." << std::endl;
            this->registrarAcao("Rodada finalizada.");
            
            this->inquiridor = nullptr;
            this->inquirido = nullptr;
            
            this->nomeInquiridor = "";
            this->nomeInquirido = "";
            
            subFaseAtual = PERGUNTA; 
            break;
    }
}

void GerenciadorDebate::executarRodadaAutomatica(int tempoPorEtapa) {
    if (this->inquiridor == nullptr || this->inquirido == nullptr) {
        std::cout << "[Erro]: Defina o inquiridor e o inquirido antes de iniciar o fluxo!" << std::endl;
        return;
    }

    for (int i = 0; i < 4; i++) {
        this->proximaAcao();
        this->cronometro.iniciar(tempoPorEtapa);
        std::this_thread::sleep_for(std::chrono::seconds(tempoPorEtapa));
        
        std::cout << "\n[Tempo Esgotado!] Fim do tempo para esta etapa.\n" << std::endl;
    }

    this->proximaAcao();
}