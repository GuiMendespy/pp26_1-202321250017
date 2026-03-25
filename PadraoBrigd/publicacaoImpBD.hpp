#ifndef PUBLICACAOIMPBD_HPP
#define  PUBLICACAOIMPBD_HPP
#include<iostream>
#include <string.h>
#include "implementador.hpp"
#include "publicacao.hpp"

using namespace std;

class publicacaoImpBD: public implementador{

    public:
        string obterDados(string tipo) override;
};

#endif