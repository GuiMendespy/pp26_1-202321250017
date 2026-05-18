#pragma once

class InterfaceGUI {
private:
    // Atributos simulando componentes de uma biblioteca gráfica (Ex: Qt)
    bool janelaVisivel;
    int larguraJanela;
    int alturaJanela;

    // Métodos internos para simular o clique dos botões da tela
    void aoClicarBotaoConfigurar();
    void aoClicarBotaoIniciar();
    void aoClicarBotaoSortear();
    void aoClicarBotaoAvancar();
    void aoClicarBotaoFechar();

public:
    InterfaceGUI();
    
    // Inicializa a janela gráfica e renderiza os elementos visuais
    void renderizarJanela();
};