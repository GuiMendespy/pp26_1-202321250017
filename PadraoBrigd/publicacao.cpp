#include "publicacao.hpp"

publicacao::publicacao(implementador* i) : imp(i) {}

string publicacao::obterDados(string tipo) {
    return imp->obterDados(tipo);
}

publicacao::~publicacao() {}