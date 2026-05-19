#include "InterfaceCLI.hpp"
#include "Facade.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

InterfaceCLI::InterfaceCLI(const vector<Candidato*>& listaOriginal, std::string ttyNovo) {
    this->candidatosDaInterface = listaOriginal;
    this->terminalJanelaNova = ttyNovo;
    this->nome;
}

void InterfaceCLI::exibirMenu() {
    int opcao = 0;
    
    std::ofstream outTerm(this->terminalJanelaNova);
    std::ifstream inTerm(this->terminalJanelaNova);

    if (!outTerm.is_open()) {
        std::cout << "[Erro]: Não foi possível se conectar à nova janela de terminal. Rodando no original." << std::endl;
        return; 
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    
    do {
        outTerm << "\n--- PAINEL DO DEBATE (CLI - NOVA JANELA) ---" << std::endl;
        outTerm << "1. Configurar Debate" << std::endl;
        outTerm << "2. Iniciar Debate" << std::endl;
        outTerm << "3. Sortear Próximo Inquiridor" << std::endl;
        outTerm << "4. Avançar Etapa" << std::endl;
        outTerm << "5. Finalizar Debate e Gerar Relatório" << std::endl;
        outTerm << "6. Sair" << std::endl;
        outTerm << "Escolha uma opção: " <<endl;
        
        inTerm >> opcao;

        switch(opcao) {
            case 1: {
                int tempoPadrao = 60;
                Facade::getInstance().configurarDebate(this->candidatosDaInterface, tempoPadrao);
                outTerm << "[CLI]: Configurado com sucesso!" << std::endl;
                break;
            }
            case 2:
                Facade::getInstance().iniciarDebate();
                break;
            case 3: {
                if (!this->candidatosDaInterface.empty()) {
                    std::uniform_int_distribution<> distrib(0, this->candidatosDaInterface.size() - 1);
                    int indiceSorteado = distrib(gen);

                    Facade::getInstance().sortearInquiridor();
                    Facade::getInstance().definirInquirido(indiceSorteado);
                } else {
                    std::cout << "[Erro]: Nenhum candidato carregado para o sorteio!" << std::endl;
                }
                break;
            }
            case 4: { 
                int tempoDesejado;
                outTerm << "Digite o tempo em segundos para cada etapa (ex: 5): " << endl;
                inTerm >> tempoDesejado;

                std::cout << "\n=== INICIANDO RODADA AUTOMÁTICA EM TEMPO REAL ===" << std::endl;
                
                Facade::getInstance().iniciarRodadaAutomatica(tempoDesejado);
                
                std::cout << "=== FIM DA RODADA AUTOMÁTICA ===" << std::endl;
                break;
            }
            case 5:
                Facade::getInstance().fincalizarDebate();
                break;
            case 6:
                std::cout << "Saindo da interface CLI..." << std::endl;
                outTerm << "Saindo da interface CLI..." << std::endl;
                system("pkill xterm");
                break;
            default:
                outTerm << "Opção inválida! Tente novamente." << std::endl;        }
    } while (opcao != 6);
}