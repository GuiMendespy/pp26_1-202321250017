#include "usuario.hpp"

Usuario::Usuario(std::string nome, double matric, std::string senha)
    : nome(nome), matric(matric), senha(senha), pontos(0) {}

std::string Usuario::getNome() { return nome; }
double Usuario::getMatric() { return matric; }
std::string Usuario::getSenha() { return senha; }
int Usuario::getRanking() { return pontos; }

bool Usuario::verificaSenha(std::string s) {
    return senha == s;
}

void Usuario::adicionarPontos(int p) {
    pontos += p;
}