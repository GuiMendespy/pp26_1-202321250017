#include "Facade.hpp"
#include <iostream>

// 1. Inicialização do atributo estático (obrigatório em C++)
Facade Facade::instance;

// Retorna a referência para a única instância do Singleton
Facade&  Facade::getInstance() {
    return instance; 
}

// Configura o debate repassando os candidatos e o tempo para o gerenciador
void Facade::configurarDebate(vector<Candidato*> candidatos, int tempos) {
    // Aqui a Facade encapsula a complexidade e repassa os dados para o gerenciador interno
    // Exemplo: this->gerenciador.definirParticipantes(candidatos);
    //          this->gerenciador.configurarCronometro(tempos);
    std::cout << "Debate configurado com " << candidatos.size() << " candidatos e tempo de " << tempos << "s." << std::endl;
}

// Aciona a lógica de sorteio dentro do gerenciador
void Facade::sortearInquiridor() {
    // Exemplo: this->gerenciador.sortearQuemPergunta();
    std::cout << "Inquiridor sorteado pelo gerenciador." << std::endl;
}

// Define quem responderá a pergunta atual
void Facade::definirInquirido(int idCandidato) {
    // Exemplo: this->gerenciador.setInquirido(idCandidato);
    std::cout << "Candidato " << idCandidato << " definido como inquirido." << std::endl;
}

// Dá o pontapé inicial nas regras do debate
void Facade::iniciarDebate() {
    // Exemplo: this->gerenciador.comecarRodada();
    std::cout << "O debate foi iniciado oficialmente!" << std::endl;
}

// Passa para o próximo turno ou próxima fase do debate
void Facade::avancarEtapa() {
    // Exemplo: this->gerenciador.proximoTurno();
    std::cout << "Avançando para a próxima etapa do debate." << std::endl;
}

// Encerra as atividades do debate e possivelmente exibe relatórios do Logger
void Facade::fincalizarDebate() {
    // Exemplo: this->gerenciador.encerrar();
    std::cout << "Debate finalizado com sucesso." << std::endl;
}

Logger& Facade::getLogger() {
    return this->logger;
}