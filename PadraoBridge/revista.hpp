#ifndef REVISTA_HPP
#define REVISTA_HPP

#include<iostream>
#include <string.h>
#include "publicacao.hpp"
using namespace std;

class revista: public publicacao{

    public:
        revista(implementador *i);
        string getArtigo();
        string getTitulo();
        string getAutor(int id);
};

#endif