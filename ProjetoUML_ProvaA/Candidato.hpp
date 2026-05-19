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
    // Construtor com valor padrão para o nome
    Candidato(string nomeInicial = "");
    
    // Destrutor virtual (boa prática para classes que podem ter herança, como CandidatoConcreto)
    virtual ~Candidato() = default;

    void marcarComoInquiridor();
    
    // CORREÇÃO: Removido o parâmetro 'string nome' que não deve existir em um Get
    string getNome() const; 
    int getId() const;
};