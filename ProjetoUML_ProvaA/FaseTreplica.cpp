#include "FaseTreplica.hpp"
#include "GerenciadorDebate.hpp"
#include "FaseDefesaDR.hpp"
#include "FimDaRodada.hpp"
#include <iostream>

void FaseTreplica::processarFase(GerenciadorDebate* ger, int tempoPorEtapa) {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "--- ETAPA: TREPLICA ---" << std::endl;
    std::cout << ">> " << ger->getNomeInquirido() << " esta na treplica." << std::endl;
    std::cout << "==========================================" << std::endl;

    ger->setCandidatoAtualPorNome(ger->getNomeInquirido());
    ger->registrarAcao("Etapa: TREPLICA. Falando: " + ger->getNomeInquirido());

    // Fim do ciclo: verifica se ha DR pendente
    if (!ger->getFilaDR().empty()) {
        std::cout << "\n[Gerenciador]: Fim do ciclo. Ha solicitacoes de Direito de Resposta pendentes." << std::endl;
        ger->registrarAcao("Ciclo encerrado. Iniciando processamento de DRs.");
        ger->setSubFase(new FaseDefesaDR());
    } else {
        std::cout << "\n[Gerenciador]: Fim do ciclo. Sem DRs pendentes. Encerrando rodada." << std::endl;
        ger->registrarAcao("Ciclo encerrado. Sem DRs. Rodada finalizada.");
        ger->setSubFase(new FimDaRodada());
    }
}
