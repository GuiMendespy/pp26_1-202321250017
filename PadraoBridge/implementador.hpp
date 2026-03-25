#ifndef IMPLEMENTADOR_HPP
#define IMPLEMENTADOR_HPP
#include<iostream>
#include <string.h>
using namespace std;

class implementador{
    public:
        virtual string obterDados(string tipo) = 0;
        virtual ~implementador(){}
};

#endif