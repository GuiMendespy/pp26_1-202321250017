#pragma once
#include <vector>
#include "Candidato.hpp"

class InterfaceCLI {
private:
    std::vector<Candidato*> candidatosDaInterface;
    std::string terminalJanelaNova;
    string nome;

public:
    InterfaceCLI(const std::vector<Candidato*>& listaOriginal,std::string ttyNovo);
    
    void exibirMenu();
};