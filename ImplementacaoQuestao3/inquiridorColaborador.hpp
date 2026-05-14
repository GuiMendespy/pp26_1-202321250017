#ifndef INQUIRIDOR_COLABORADOR_H
#define INQUIRIDOR_COLABORADOR_H
#include "politicoColaborador.hpp"

class InquiridorColaborador : public PoliticoColaborador {
public:
    InquiridorColaborador(std::string n);
    PoliticoColaborador* escolher_inquirido(PoliticoColaborador* p);
};
#endif