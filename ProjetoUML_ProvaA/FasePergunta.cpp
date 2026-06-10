#include "FasePergunta.hpp"
#include "FaseResposta.hpp"
#include "GerenciadorDebate.hpp"
#include <iostream>

void FasePergunta::processarFase(GerenciadorDebate* ger, int tempoPorEtapa) {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "--- ETAPA: PERGUNTA ---" << std::endl;
    std::cout << ">> " << ger->getNomeInquiridor() << " esta fazendo a pergunta." << std::endl;
    std::cout << "==========================================" << std::endl;

    ger->setCandidatoAtualPorNome(ger->getNomeInquiridor());
    ger->registrarAcao("Etapa: PERGUNTA. Falando: " + ger->getNomeInquiridor());
    ger->setSubFase(new FaseResposta());
}
