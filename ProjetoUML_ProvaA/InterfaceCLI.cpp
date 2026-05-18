#include "InterfaceCLI.hpp"
#include "Facade.hpp"
#include <iostream>

InterfaceCLI::InterfaceCLI() {}

void InterfaceCLI::exibirMenu() {
    int opcao = 0;
    
    do {
        std::cout << "\n--- PAINEL DO DEBATE (CLI) ---" << std::endl;
        std::cout << "1. Configurar Debate" << std::endl;
        std::cout << "2. Iniciar Debate" << std::endl;
        std::cout << "3. Sortear Próximo Inquiridor" << std::endl;
        std::cout << "4. Avançar Etapa" << std::endl;
        std::cout << "5. Finalizar Debate e Gerar Relatório" << std::endl;
        std::cout << "6. Sair" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        // Todas as opções chamam diretamente o Singleton da Facade
        switch(opcao) {
            case 1: {
                // Criando um vetor temporário de candidatos apenas para exemplo do método
                std::vector<Candidato*> candidatos Dummy; 
                Facade::getInstance().configurarDebate(candidatosDummy, 60);
                break;
            }
            case 2:
                Facade::getInstance().iniciarDebate();
                break;
            case 3:
                Facade::getInstance().sortearInquiridor();
                break;
            case 4:
                Facade::getInstance().avancarEtapa();
                break;
            case 5:
                Facade::getInstance().fincalizarDebate();
                break;
            case 6:
                std::cout << "Saindo da interface CLI..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida! Tente novamente." << std::endl;
        }
    } while (opcao != 6);
}