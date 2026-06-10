#include "FaseResposta.hpp"
#include "GerenciadorDebate.hpp"
#include "FaseReplica.hpp"
#include <iostream>

void FaseResposta::processarFase(GerenciadorDebate* ger, int tempoPorEtapa) {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "--- ETAPA: RESPOSTA ---" << std::endl;
    std::cout << ">> " << ger->getNomeInquirido() << " esta respondendo." << std::endl;
    std::cout << "==========================================" << std::endl;

    ger->setCandidatoAtualPorNome(ger->getNomeInquirido());
    ger->registrarAcao("Etapa: RESPOSTA. Falando: " + ger->getNomeInquirido());
    ger->setSubFase(new FaseReplica());
}
