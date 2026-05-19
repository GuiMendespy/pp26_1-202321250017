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
    Candidato(string nomeInicial = "");
    
    virtual ~Candidato() = default;

    void marcarComoInquiridor();
    
    string getNome() const; 
    int getId() const;
};