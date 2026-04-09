#include "ranking.hpp"
#include <algorithm>

void Ranking::atualizar(std::vector<Usuario> lista) {
    usuarios = lista;
}

void Ranking::ordenar() {
    std::sort(usuarios.begin(), usuarios.end(), [](Usuario &a, Usuario &b) {
        return a.getMatric() > b.getMatric(); // ajusta pra pontos depois
    });
}

std::vector<Usuario> Ranking::getRanking() {
    return usuarios;
}