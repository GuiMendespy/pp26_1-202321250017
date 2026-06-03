#include "Microfone.hpp"
#include <iostream>

Microfone::Microfone() : id(0), ligado(false) {
}

void Microfone::ligar() {
    if (!ligado) {
        this->ligado = true;
        std::cout << "[Microfone]: Ligado. Som liberado." << std::endl;
    } else {
        std::cout << "[Microfone]: Já está ligado." << std::endl;
    }
}

void Microfone::desligar() {
    if (ligado) {
        this->ligado = false;
        std::cout << "[Microfone]: Desligado. Mudo." << std::endl;
    } else {
        std::cout << "[Microfone]: Já está desligado." << std::endl;
    }
}