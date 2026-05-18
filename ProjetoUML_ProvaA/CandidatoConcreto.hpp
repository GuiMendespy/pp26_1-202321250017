#pragma once
#include <vector>
#include "Candidato.hpp"
#include "Observador.hpp"

class CandidatoConcreto : public Candidato {
    private:
        vector<Observador*> observadores;
    public:
        CandidatoConcreto();
        void registrar(Observador* o);
        void remover(Observador* o);
        void notificar();
        void marcarComoInquisidor();
};