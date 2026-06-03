#pragma once
#include <string>
#include "Microfone.hpp"
#include "Prototipo.hpp"

using namespace std;

class Candidato : public Prototipo {
private:
    int id;
    string nome;
    bool jaPerguntou;
    Microfone microfone;
    friend class CandidatoConcretoBuilder;

public:
    Candidato(string nomeInicial = "", Microfone* m = nullptr);
    Candidato(const Candidato& outro);
    virtual ~Candidato() = default;

    void marcarComoInquiridor();
    string getNome() const; 
    int getId() const;
    
    //virtual Prototipo* clonar() const override = 0;
};