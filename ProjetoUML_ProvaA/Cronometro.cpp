#include "Cronometro.hpp"
#include <iostream> // Incluído caso queira exibir mensagens no console durante os testes

// Construtor: Inicializa o tempo atual zerado
Cronometro::Cronometro() : tempoAtual(0) {
    // Inicializações adicionais, se houver
}

// Inicia o cronômetro com o tempo definido por parâmetro
void Cronometro::iniciar(int tempo) {
    if (tempo > 0) {
        this->tempoAtual = tempo;
        // Aqui você poderá futuramente implementar loops com std::this_thread::sleep_for
        // para decrementar o tempo segundo a segundo se o seu sistema rodar em tempo real.
    } else {
        this->tempoAtual = 0;
    }
}

// Zera o tempo atual indicando que o prazo da fala ou do debate encerrou
void Cronometro::finalizarTempo() {
    this->tempoAtual = 0;
}