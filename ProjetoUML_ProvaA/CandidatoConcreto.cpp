#include "CandidatoConcreto.hpp"
#include <algorithm>
#include <iostream>

CandidatoConcreto::CandidatoConcreto() : Candidato("", nullptr) {}

CandidatoConcreto::CandidatoConcreto(const CandidatoConcreto& outro) : Candidato(outro) {
    this->observadores = outro.observadores;
    std::cout << "[PROTOTYPE] Objeto CandidatoConcreto totalmente duplicado via cópia profunda." << std::endl;
}

Prototipo* CandidatoConcreto::clonar() const {
    return std::make_unique<CandidatoConcreto>(*this).release();
}

void CandidatoConcreto::registrar(Observador* o) { observadores.push_back(o); }

void CandidatoConcreto::remover(Observador* o) {
    observadores.erase(std::remove(observadores.begin(), observadores.end(), o), observadores.end());
}

void CandidatoConcreto::notificar() {
    for (Observador* obs : observadores) {
        obs->atualizar("Candidato " + getNome() + " atualizou seu estado.");
    }
}

void CandidatoConcreto::marcarComoInquisidor() { 
    Candidato::marcarComoInquiridor(); 
}