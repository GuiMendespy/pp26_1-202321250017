#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>

class Usuario {
private:
    std::string nome;
    double matric;
    std::string senha;
    int pontos;

public:
    Usuario(std::string nome, int matric, std::string senha);

    std::string getNome();
    double getMatric();
    std::string getSenha();

    bool verificaSenha(std::string senha);
    void adicionarPontos(int pontos);
};

#endif