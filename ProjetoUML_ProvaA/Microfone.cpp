#include "Microfone.hpp"
#include <iostream>

// Construtor: Inicializa o ID padrão e o microfone como desligado (false)
Microfone::Microfone() : id(0), ligado(false) {
    // Se você quiser passar o ID por parâmetro futuramente, 
    // basta alterar o construtor no .hpp para: Microfone(int id);
}

// Altera o estado para ligado
void Microfone::ligar() {
    if (!ligado) {
        this->ligado = true;
        std::cout << "[Microfone]: Ligado. Som liberado." << std::endl;
    } else {
        std::cout << "[Microfone]: Já está ligado." << std::endl;
    }
}

// Altera o estado para desligado
void Microfone::desligar() {
    if (ligado) {
        this->ligado = false;
        std::cout << "[Microfone]: Desligado. Mudo." << std::endl;
    } else {
        std::cout << "[Microfone]: Já está desligado." << std::endl;
    }
}