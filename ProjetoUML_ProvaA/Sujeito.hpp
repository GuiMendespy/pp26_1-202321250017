#pragma once
#include "Observador.hpp"

class Sujeito {
public:
    Sujeito();
    virtual ~Sujeito();
    virtual void registrar(Observador* o) = 0;
    virtual void remover(Observador* o) = 0;
    virtual void notificar() = 0;
};