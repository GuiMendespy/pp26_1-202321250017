#include "FimDaRodada.hpp"
#include "GerenciadorDebate.hpp"
#include <iostream>
#include "FasePergunta.hpp"

void FimDaRodada::processarFase(GerenciadorDebate* ger, int tempoPorEtapa) {
    std::cout << "\n[Gerenciador]: Rodada encerrada." << std::endl;
    ger->registrarAcao("Rodada finalizada.");

    ger->resetarRodada();
    ger->setSubFase(new FasePergunta());
}
