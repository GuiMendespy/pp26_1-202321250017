#include "Facade.hpp"
#include "GerenciadorDebate.hpp"
#include "CandidatoConcretoBuilder.hpp" 
#include <iostream>

Facade Facade::instance;

Facade::Facade() {
    this->gerenciador = new GerenciadorDebate();
    this->candidato = nullptr; // Inicializado como nulo, pois os candidatos reais vêm do Builder via configurarDebate
}

Facade& Facade::getInstance() {
    return instance; 
}

void Facade::configurarDebate(vector<CandidatoConcreto*> candidatos, int tempos) {
    this->gerenciador->registrarAcao("FACADE: Recebendo lista de candidatos do Builder e enviando para o Gerenciador.");
    
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

void Facade::avancarEtapa() {
    this->gerenciador->proximaAcao();
    std::cout << "[FACADE]: Avançando para a próxima etapa do debate." << std::endl;
}

void Facade::fincalizarDebate() {
    this->gerenciador->registrarAcao("FACADE: Encerrando o debate e gerando relatório final.");
    std::cout << "[FACADE]: Debate finalizado com sucesso." << std::endl;
    
    this->logger.gerarRelatorio();
}

Logger& Facade::getLogger() {
    return this->logger;
}

void Facade::iniciarRodadaAutomatica(int tempoPorEtapa) {
    this->gerenciador->executarRodadaAutomatica(tempoPorEtapa);
}