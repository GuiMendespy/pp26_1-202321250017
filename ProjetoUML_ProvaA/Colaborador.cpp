#include "Colaborador.hpp"

// Construtor: Inicializa o ponteiro do mediador como nulo (segurança)
Colaborador::Colaborador() : mediador(nullptr) {
    // Outras inicializações da classe, se houver
}

// Define ou altera o mediador deste colaborador em tempo de execução
void Colaborador::setMediador(Mediador* mediador) {
    this->mediador = mediador;
}