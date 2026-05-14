#include "gerenciadorPolitico.hpp"
#include "inquiridorColaborador.hpp"
#include <cstdlib>

GerenciadorPoliticos::GerenciadorPoliticos() : total_sorteados(0) {}

PoliticoColaborador* GerenciadorPoliticos::criar_politico(std::string nome, Mediador* m) {
    PoliticoColaborador* novo = new InquiridorColaborador(nome); 
    novo->set_mediador(m); 
    politicos.push_back(novo); 
    return novo;
}

PoliticoColaborador* GerenciadorPoliticos::sortear() {
    if (total_sorteados >= politicos.size()) return nullptr;
    PoliticoColaborador* p;
    do {
        p = politicos[rand() % politicos.size()]; 
    } while (p->get_sorteado() && total_sorteados < politicos.size()); 
    
    total_sorteados++; 
    p->set_sorteado(true); 
    return p; 
}

PoliticoColaborador* GerenciadorPoliticos::obter_politico(std::string nome) {
    for(auto p : politicos) if(p->get_name() == nome) return p;
    return nullptr;
}