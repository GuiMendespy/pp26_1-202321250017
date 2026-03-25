#ifndef PUBLICACAO_HPP
#define PUBLICACAO_HPP

#include "implementador.hpp"
#include <string>

class publicacao {
protected:
    implementador* imp;

public:
    publicacao(implementador* i);

    virtual string obterDados(string tipo);

    virtual string getTitulo() = 0;
    int getAutor(int id);

    virtual ~publicacao();
};

#endif