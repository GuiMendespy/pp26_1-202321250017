#include "FaseDefesaDR.hpp"
#include "GerenciadorDebate.hpp"
#include "FimDaRodada.hpp"

#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <queue>

void FaseDefesaDR::processarFase(
    GerenciadorDebate* ger,
    int tempoPorEtapa
) {
    ger->setDRBloqueado(true);

    auto& fila = ger->getFilaDR();

    std::cout << "\n=========================================="
              << std::endl;
    std::cout << "FILA DE DIREITOS DE RESPOSTA"
              << std::endl;
    std::cout << "=========================================="
              << std::endl;

    if (fila.empty()) {
        std::cout << "Nenhum DR solicitado."
                  << std::endl;
    } else {

        std::queue<Candidato*> copiaFila = fila;

        while (!copiaFila.empty()) {
            std::cout << "- "
                      << copiaFila.front()->getNome()
                      << std::endl;

            copiaFila.pop();
        }
    }

    // Sorteio da decisão do gerenciador
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(0,1);

    int decisao = dist(gen);

    std::cout << "\n[GERENCIADOR]"
              << std::endl;

    if (decisao == 0) {

        std::cout
            << "Decisao: NAO conceder DR."
            << std::endl;

        while (!fila.empty()) {
            fila.pop();
        }

        std::cout
            << "Fila de DRs apagada."
            << std::endl;

        ger->registrarAcao(
            "Gerenciador recusou todos os DRs."
        );

        ger->setDRBloqueado(false);

        ger->setSubFase(new FimDaRodada());

        return;
    }

    std::cout
        << "Decisao: CONCEDER DR."
        << std::endl;

    ger->registrarAcao(
        "Gerenciador aprovou os DRs."
    );

    while (!fila.empty()) {

        Candidato* defensor = fila.front();
        fila.pop();

        std::cout
            << "\n=========================================="
            << std::endl;

        std::cout
            << "--- DIREITO DE RESPOSTA ---"
            << std::endl;

        std::cout
            << ">> "
            << defensor->getNome()
            << " tem a palavra por "
            << tempoPorEtapa
            << " segundos."
            << std::endl;

        std::cout
            << "=========================================="
            << std::endl;

        ger->setCandidatoAtual(defensor);

        std::string msg =
            "[DR] " +
            defensor->getNome() +
            " esta exercendo seu Direito de Resposta.";

        ger->notificarTodos(msg);

        ger->registrarAcao(
            "DR iniciado para: "
            + defensor->getNome()
        );

        ger->getCronometro().iniciar(
            tempoPorEtapa
        );

        std::this_thread::sleep_for(
            std::chrono::seconds(
                tempoPorEtapa
            )
        );

        std::cout
            << "[Tempo Esgotado] Fim do DR de "
            << defensor->getNome()
            << "."
            << std::endl;

        ger->registrarAcao(
            "DR encerrado para: "
            + defensor->getNome()
        );
    }

    ger->setDRBloqueado(false);

    std::cout
        << "\n[Gerenciador]: Todos os DRs processados."
        << std::endl;

    ger->registrarAcao(
        "Todos os DRs processados."
    );

    ger->setSubFase(
        new FimDaRodada()
    );
}