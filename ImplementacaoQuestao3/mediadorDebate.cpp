#include "mediadorDebate.hpp"
#include "configuracao.hpp"
#include "logger.hpp"
#include <iostream>

MediadorDebate::MediadorDebate() : inquiridor(nullptr), inquirido(nullptr) {}

void MediadorDebate::set_inquiridor(PoliticoColaborador* p) {
    // Apenas atribui o ponteiro existente, sem criar novo objeto
    this->inquiridor = static_cast<InquiridorColaborador*>(p); 
}

void MediadorDebate::set_inquirido(PoliticoColaborador* p) {
    // Apenas referencia o político escolhido
    // REMOVIDO: delete inquirido e new InquiridoColaborador
    this->inquirido = static_cast<InquiridoColaborador*>(p); 
}

void MediadorDebate::debate(Configuracao& config) {
    // Validação de segurança
    if (!inquiridor || !inquirido) {
        Logger::get_instance()->register_log("Erro: Inquiridor ou Inquirido nao definidos.");
        return;
    }

    Logger* log = Logger::get_instance(); 
    
    log->register_log("Pergunta"); 
    inquiridor->falar(config.get_pergunta_tempo()); 
    
    log->register_log("Resposta"); 
    inquirido->falar(config.get_resposta_tempo()); 
    
    log->register_log("Replica"); 
    inquiridor->falar(config.get_replica_tempo()); 
    
    log->register_log("Treplica"); 
    inquirido->falar(config.get_treplica_tempo()); 
}