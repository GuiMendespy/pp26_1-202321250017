#include "Cronometro.hpp"
#include <iostream> 

Cronometro::Cronometro() : tempoAtual(0) {
    
}

void Cronometro::iniciar(int tempo) {
    if (tempo > 0) {
        this->tempoAtual = tempo;
        
    } else {
        this->tempoAtual = 0;
    }
}

void Cronometro::finalizarTempo() {
    this->tempoAtual = 0;
}