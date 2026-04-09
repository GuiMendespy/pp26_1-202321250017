#ifndef TERMINAL_HPP
#define TERMINAL_HPP

class Terminal {
private:
    bool statusTerminal;

public:
    void iniciar();
    bool telaLogin();
    void menuPrincipal();
    void telaCadastro();
    void telaDescarte();
    void telaRanking();
};

#endif