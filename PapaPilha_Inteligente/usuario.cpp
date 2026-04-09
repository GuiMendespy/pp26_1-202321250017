#include "usuario.hpp"

Usuario::Usuario(std::string nome, int matric, std::string senha)
    : nome(nome), matric(matric), senha(senha), pontos(0) {}

std::string Usuario::getNome() { return nome; }
int Usuario::getMatric() { return matric; }
std::string Usuario::getSenha() { return senha; }

bool Usuario::verificaSenha(std::string s) {
    return senha == s;
}

void Usuario::adicionarPontos(int p) {
    pontos += p;
}