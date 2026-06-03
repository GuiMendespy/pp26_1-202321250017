#pragma once
#include <vector>
#include <string>

// Declaração antecipada do novo tipo criado pelo Builder
class CandidatoConcreto;

class InterfaceCLI {
private:
    std::vector<CandidatoConcreto*> candidatosDaInterface;
    std::string terminalJanelaNova;
    std::string nome;

public:
    InterfaceCLI(const std::vector<CandidatoConcreto*>& listaOriginal, std::string ttyNovo);
    void exibirMenu();
};