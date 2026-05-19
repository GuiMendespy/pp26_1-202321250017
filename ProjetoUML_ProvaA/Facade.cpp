#include "Facade.hpp"
#include "GerenciadorDebate.hpp"
#include "Candidato.hpp"
#include <iostream>

Facade Facade::instance;

Facade::Facade() {
    this->gerenciador = new GerenciadorDebate();
    this->candidato = new Candidato();
}

Facade& Facade::getInstance() {
    return instance; 
}

// Configura o debate repassando os candidatos e o tempo para o gerenciador
void Facade::configurarDebate(vector<Candidato*> candidatos, int tempos) {
    this->gerenciador->registrarAcao("FACADE: Recebendo lista de candidatos e enviando para o Gerenciador.");
    
    this->gerenciador->setCandidatos(candidatos); 
    

}

void Facade::registrarObservador(Observador* obs) {
    this->gerenciador->registrarObservador(obs);
}

// Aciona a lógica de sorteio dentro do gerenciador
void Facade::sortearInquiridor() {
    this->gerenciador->sortearInquiridor();
    this->gerenciador->registrarAcao("[FACADE]: Inquiridor sorteado pelo gerenciador.");
    
}

// Define quem responderá a pergunta atual
void Facade::definirInquirido(int idCandidato) {
    this->gerenciador->definirInquirido(idCandidato);
    this->gerenciador->registrarAcao("[FACADE]: Candidato definido como inquirido.");
}

// Dá o pontapé inicial nas regras do debate
void Facade::iniciarDebate() {
    this->gerenciador->iniciarFase(60); 
    this->gerenciador->registrarAcao("O debate foi iniciado oficialmente!");
}

void Facade::avancarEtapa() {
    this->gerenciador->proximaAcao();
    std::cout << "[FACADE]: Avançando para a próxima etapa do debate." << std::endl;
}

// Encerra as atividades do debate e exibe o relatório acumulado do Logger
void Facade::fincalizarDebate() {
    this->gerenciador->registrarAcao("FACADE: Encerrando o debate e gerando relatório final.");
    std::cout << "[FACADE]: Debate finalizado com sucesso." << std::endl;
    
    this->logger.gerarRelatorio();
}

// Retorna o Logger interno da Facade
Logger& Facade::getLogger() {
    return this->logger;
}

void Facade::iniciarRodadaAutomatica(int tempoPorEtapa) {
    this->gerenciador->executarRodadaAutomatica(tempoPorEtapa);
}