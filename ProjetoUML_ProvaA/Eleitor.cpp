#include "Eleitor.hpp"
#include <iostream>

Eleitor::Eleitor(int idFavorito)
    : idCandidatoFavorito(idFavorito), candidatoId(0) 
    {
        std::cout << "[PROTOTYPE] Objeto Eleitor totalmente duplicado via cópia profunda." << std::endl;
    }


Eleitor* Eleitor::clonar() const {
    return new Eleitor(*this);
}

void Eleitor::atualizar(std::string msg) {
    std::cout << "[Eleitor do Candidato " << this->idCandidatoFavorito
              << "] Recebeu notificação: " << msg << std::endl;
}

int Eleitor::getCandidatoId() {
    return this->idCandidatoFavorito;
}

std::string Eleitor::exibirNotificacao() const {
    return "Notificação para o Eleitor: " + this->nome;
}
