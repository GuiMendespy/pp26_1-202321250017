#ifndef GERENCIADOR_POLITICOS_H
#define GERENCIADOR_POLITICOS_H
#include <vector>
#include "politicoColaborador.hpp"

class GerenciadorPoliticos {
private:
    std::vector<PoliticoColaborador*> politicos; 
    size_t total_sorteados;
public:
    GerenciadorPoliticos();
    PoliticoColaborador* criar_politico(std::string nome, Mediador* m); 
    PoliticoColaborador* sortear(); 
    PoliticoColaborador* obter_politico(std::string nome); 
};
#endif