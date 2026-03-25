#ifndef LIVRO_HPP
#define LIVRO_HPP

#include<iostream>
#include <string.h>
#include "publicacao.hpp"
using namespace std;

class livro: public publicacao{

    public:
        livro(implementador* i);
        string getISBN();
        string getTitulo();
        string getAutor();
};

#endif