#include "bancoDedados.hpp"

void BancoDeDados::inserirUsuario(Usuario usuario) {
    usuarios.push_back(usuario);
}

Usuario* BancoDeDados::buscarUsuario(double matric) {
    for (auto &u : usuarios) {
        if (u.getMatric() == matric)
            return &u;
    }
    return nullptr;
}

std::vector<Usuario> BancoDeDados::listarRanking() {
    return usuarios;
}