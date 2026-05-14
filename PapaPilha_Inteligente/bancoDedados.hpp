#ifndef BANCODEDADOS_HPP
#define BANCODEDADOS_HPP

#include <vector>
#include "usuario.hpp"

class BancoDeDados {
private:
    std::vector<Usuario> usuarios;

public:
    void inserirUsuario(Usuario usuario);
    Usuario* buscarUsuario(double matric);
    std::vector<Usuario> listarRanking();
};

#endif