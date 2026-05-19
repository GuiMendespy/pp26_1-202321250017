#include "Eleitor.hpp"
#include <iostream>

Eleitor::Eleitor(int idFavorito) {
    this->idCandidatoFavorito = idFavorito;
}
void Eleitor::atualizar(string msg) {
    // Agora o eleitor só vai printar isso se ele for do candidato certo!
    cout << "[Eleitor do Candidato " << this->idCandidatoFavorito << "] Recebeu notificação: " << msg << endl;
}

int Eleitor::getCandidatoId() {
    return this->idCandidatoFavorito;
}

string Eleitor::exibirNotificacao() {
    return "Notificação para o Eleitor: " + this->nome; 
}