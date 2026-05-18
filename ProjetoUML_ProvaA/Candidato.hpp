#pragma once
#include <string>
#include "Microfone.hpp"
using namespace std;

class Candidato {

private:
    int id;
    string nome;
    bool jaPerguntou;
    Microfone microfone;

public:
    Candidato();
    void marcarComoInquiridor();
};
