#ifndef RANKING_HPP
#define RANKING_HPP

#include <vector>
#include "usuario.hpp"

class Ranking {
private:
    std::vector<Usuario> usuarios;

public:
    void atualizar(std::vector<Usuario> lista);
    void ordenar();
    std::vector<Usuario> getRanking();
};

#endif