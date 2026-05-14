#include "politicoColaborador.hpp"
#include "mediator.hpp"

PoliticoColaborador::PoliticoColaborador(std::string n) : name(n), mediador(nullptr), sorteado(false) {}
void PoliticoColaborador::set_mediador(Mediador* m) { mediador = m; }
void PoliticoColaborador::set_sorteado(bool s) { sorteado = s; }
bool PoliticoColaborador::get_sorteado() { return sorteado; }
std::string PoliticoColaborador::get_name() { return name; }

void PoliticoColaborador::falar(int tempo) {
    microfone.ativar(); 
    microfone.esperar_tempo(tempo); 
    microfone.desativar(); 
}