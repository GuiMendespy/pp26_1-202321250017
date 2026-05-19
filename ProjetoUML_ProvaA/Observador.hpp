#pragma once
#include <string>
#include "Candidato.hpp"
using namespace std;

class Observador {
public:
    Observador() = default;
    virtual ~Observador() = default;
    virtual void atualizar(string msg) = 0;
    virtual int getCandidatoId() = 0;
};