#ifndef PUBLICACAOXML_HPP
#define  PUBLICACAOXML_HPP
#include<iostream>
#include <string.h>
#include "implementador.hpp"
#include "publicacao.hpp"

using namespace std;

class publicacaoXML: public implementador{

    public:
        string obterDados(string tipo) override;
};

#endif