#ifndef POLITICO_COLABORADOR_H
#define POLITICO_COLABORADOR_H
#include <string>
#include "microfoneCronometro.hpp"

class Mediador;

class PoliticoColaborador {
protected:
    std::string name; 
    Mediador* mediador; 
    bool sorteado; 
    MicrofoneCronometro microfone; 
public:
    PoliticoColaborador(std::string n);
    void set_mediador(Mediador* m); 
    void set_sorteado(bool s); 
    bool get_sorteado(); 
    std::string get_name();
    void falar(int tempo); 
};
#endif