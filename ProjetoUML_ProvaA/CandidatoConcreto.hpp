#pragma once
#include <vector>
#include "Candidato.hpp"
#include "Observador.hpp"

class CandidatoConcretoBuilder;

class CandidatoConcreto : public Candidato {
private:
    std::vector<Observador*> observadores;
    friend class CandidatoConcretoBuilder;

public:
    CandidatoConcreto();
    CandidatoConcreto(const CandidatoConcreto& outro);

    void registrar(Observador* o);
    void remover(Observador* o);
    void notificar();
    void marcarComoInquisidor();
    
    Prototipo* clonar() const override;
};