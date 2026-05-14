#ifndef FACHADA_HPP
#define FACHADA_HPP

#include "bancoDedados.hpp"
#include "ranking.hpp"

#include "enumeration.cpp"

class Fachada {
private:
    static Fachada* instance;
    BancoDeDados banco;

    Fachada();

public:
    static Fachada* getInstance();

    void cadastrar(std::string nome, double matric, std::string senha);
    bool autenticar(double matric, std::string senha);
    void mostrarDesempenho();
};

#endif