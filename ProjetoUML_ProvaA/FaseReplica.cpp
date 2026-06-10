#include "FaseReplica.hpp"
#include "GerenciadorDebate.hpp"
#include "FaseTreplica.hpp"
#include <iostream>

void FaseReplica::processarFase(GerenciadorDebate* ger, int tempoPorEtapa) {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "--- ETAPA: REPLICA ---" << std::endl;
    std::cout << ">> " << ger->getNomeInquiridor() << " esta na replica." << std::endl;
    std::cout << "==========================================" << std::endl;

    ger->setCandidatoAtualPorNome(ger->getNomeInquiridor());
    ger->registrarAcao("Etapa: REPLICA. Falando: " + ger->getNomeInquiridor());
    ger->setSubFase(new FaseTreplica());
}
