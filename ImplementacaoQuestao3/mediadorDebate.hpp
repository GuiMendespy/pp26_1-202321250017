#ifndef MEDIADOR_DEBATE_H
#define MEDIADOR_DEBATE_H
#include "mediator.hpp"
#include "inquiridorColaborador.hpp"
#include "inquiridoColaborador.hpp"

class MediadorDebate : public Mediador {
private:
    InquiridorColaborador* inquiridor; 
    InquiridoColaborador* inquirido; 
public:
    MediadorDebate();
    void set_inquiridor(PoliticoColaborador* p);
    void set_inquirido(PoliticoColaborador* p); 
    void debate(Configuracao& config) override; 
};
#endif