#pragma once
#include <string>
using namespace std;

class Observador {
public:
    Observador();
    virtual ~Observador();
    virtual void atualizar(string msg) = 0;
    virtual void getCandidatosId() = 0;
};