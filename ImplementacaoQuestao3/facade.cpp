#include "facade.hpp"

Facade* Facade::instance = nullptr;

Facade::Facade() {
    mediador_debate = new MediadorDebate();
    logger = Logger::get_instance(); 
    logger->register_log("Fachada iniciada"); 
}

Facade* Facade::get_instance() {
    if (!instance) instance = new Facade(); 
    return instance;
}

void Facade::configuracao_tempos(int tempos[3]) {
    config.set_pergunta_tempo(tempos[0]); 
    config.set_resposta_tempo(tempos[1]); 
    config.set_replica_tempo(tempos[2]); 
    logger->register_log("Configura tempo"); 
}

void Facade::sortear_inquiridor() {
    PoliticoColaborador* p = gerencia_politicos.sortear(); 
    mediador_debate->set_inquiridor(p);
    logger->register_log("Inquiridor sorteado"); 
}

void Facade::escolher_inquirido(std::string nome) {
    PoliticoColaborador* p = gerencia_politicos.obter_politico(nome); 
    mediador_debate->set_inquirido(p); 
    logger->register_log("inquerido escolhido"); 
}

void Facade::iniciar_debate() {
    logger->register_log("Debate iniciado"); 
    mediador_debate->debate(config);
}

void Facade::cadastrar_politico(std::string nome) {
    gerencia_politicos.criar_politico(nome, mediador_debate);
}