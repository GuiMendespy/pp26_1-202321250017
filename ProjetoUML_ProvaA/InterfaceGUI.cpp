#include "InterfaceGUI.hpp"
#include "Facade.hpp"
#include <iostream>

InterfaceGUI::InterfaceGUI() : janelaVisivel(false), larguraJanela(800), alturaJanela(600) {}

void InterfaceGUI::renderizarJanela() {
    this->janelaVisivel = true;
    std::cout << "\n[GUI] Abrindo janela gráfica " << larguraJanela << "x" << alturaJanela << "..." << std::endl;
    std::cout << "[GUI] Renderizando Botão: 'Configurar Debate'" << std::endl;
    std::cout << "[GUI] Renderizando Botão: 'Iniciar Debate'" << std::endl;
    std::cout << "[GUI] Renderizando Botão: 'Sortear'" << std::endl;
    std::cout << "[GUI] Renderizando Botão: 'Avançar'" << std::endl;
    std::cout << "[GUI] Renderizando Caixa de Logs Gráfica..." << std::endl;
    
    // Exemplo de simulação de cliques do usuário na tela:
    aoClicarBotaoConfigurar();
    aoClicarBotaoIniciar();
    aoClicarBotaoSortear();
    aoClicarBotaoAvancar();
    aoClicarBotaoFechar();
}

void InterfaceGUI::aoClicarBotaoConfigurar() {
    std::cout << "\n[GUI Evento] Usuário clicou em 'Configurar Debate'." << std::endl;
    std::vector<Candidato*> candidatosDummy;
    Facade::getInstance().configurarDebate(candidatosDummy, 45);
}

void InterfaceGUI::aoClicarBotaoIniciar() {
    std::cout << "\n[GUI Evento] Usuário clicou em 'Iniciar Debate'." << std::endl;
    Facade::getInstance().iniciarDebate();
}

void InterfaceGUI::aoClicarBotaoSortear() {
    std::cout << "\n[GUI Evento] Usuário clicou em 'Sortear'." << std::endl;
    Facade::getInstance().sortearInquiridor();
}

void InterfaceGUI::aoClicarBotaoAvancar() {
    std::cout << "\n[GUI Evento] Usuário clicou em 'Avançar'." << std::endl;
    Facade::getInstance().avancarEtapa();
}

void InterfaceGUI::aoClicarBotaoFechar() {
    std::cout << "\n[GUI Evento] Usuário fechou a janela. Encerrando e exibindo relatório..." << std::endl;
    Facade::getInstance().fincalizarDebate();
    this->janelaVisivel = false;
}