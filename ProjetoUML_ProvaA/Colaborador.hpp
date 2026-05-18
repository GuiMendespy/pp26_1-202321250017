#pragma once
#include "Mediador.hpp"
#include "Candidato.hpp"
#include "Microfone.hpp"
#include "Cronometro.hpp"


class Colaborador : public Candidato, public Microfone, public Cronometro{
    private:
        Mediador* mediador;

    public:
        Colaborador();
        void setMediador(Mediador* mediador);
};