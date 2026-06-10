#include "Facade.hpp"
#include "GerenciadorDebate.hpp"
#include "CandidatoConcretoBuilder.hpp"
#include <iostream>

Facade Facade::instance;

Facade::Facade() {
    this->gerenciador = new GerenciadorDebate();
    this->candidato   = nullptr;
}

Facade& Facade::getInstance() {
    return instance;
}

void Facade::configurarDebate(vector<CandidatoConcreto*> candidatos, int tempos) {
    this->gerenciador->registrarAcao(
        "FACADE: Recebendo lista de candidatos do Builder e enviando para o Gerenciador.");
    this->gerenciador->setCandidatos(candidatos);
}

void Facade::registrarObservador(Observador* obs) {
    this->gerenciador->registrarObservador(obs);
}

void Facade::sortearInquiridor() {
    this->gerenciador->sortearInquiridor();
    this->gerenciador->registrarAcao("[FACADE]: Inquiridor sorteado pelo gerenciador.");
}

void Facade::definirInquirido(int idCandidato) {
    this->gerenciador->definirInquirido(idCandidato);
    this->gerenciador->registrarAcao("[FACADE]: Candidato definido como inquirido.");
}

void Facade::iniciarDebate() {
    this->gerenciador->iniciarFase(60);
    this->gerenciador->registrarAcao("O debate foi iniciado oficialmente!");
}

void Facade::avancarEtapa(int tempoPorEtapa) {
    this->gerenciador->proximaAcao(tempoPorEtapa);
    cout << "[FACADE]: Avancando para a proxima etapa do debate." << endl;
}

// Novo: qualquer parte do sistema chama solicitarDR(id) na Fachada.
// A Fachada localiza o candidato e repassa ao GerenciadorDebate.
void Facade::solicitarDR(int candidatoId) {
    // O GerenciadorDebate possui a lista de candidatos; delegamos direto.
    // Usamos avancarEtapa como ponto de entrada público — aqui criamos
    // um método específico para manter a Fachada como único ponto de acesso.
    this->gerenciador->registrarAcao(
        "[FACADE]: Solicitacao de DR recebida para candidato id=" +
        to_string(candidatoId));

    // Recupera o candidato via GerenciadorDebate e solicita DR
    // (GerenciadorDebate expõe solicitarDRPorId para evitar expor o vetor inteiro)
    this->gerenciador->solicitarDRPorId(candidatoId);
}

void Facade::fincalizarDebate() {
    this->gerenciador->registrarAcao(
        "FACADE: Encerrando o debate e gerando relatorio final.");
    cout << "[FACADE]: Debate finalizado com sucesso." << endl;
    this->logger.gerarRelatorio();
}

Logger& Facade::getLogger() {
    return this->logger;
}

void Facade::iniciarRodadaAutomatica(int tempoPorEtapa) {
    this->gerenciador->executarRodadaAutomatica(tempoPorEtapa);
}
