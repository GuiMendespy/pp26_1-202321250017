#include "Facade.hpp"
#include <iostream>

Fachada* Fachada::instance = nullptr;

Fachada::Fachada() {}

Fachada* Fachada::getInstance() {
    if (instance == nullptr)
        instance = new Fachada();
    return instance;
}

void Fachada::cadastrar(std::string nome, double matric, std::string senha) {
    Usuario u(nome, matric, senha);
    banco.inserirUsuario(u);
}

bool Fachada::autenticar(double matric, std::string senha) {
    Usuario* u = banco.buscarUsuario(matric);

    if (u && u->verificaSenha(senha))
        return true;

    return false;
}

void Fachada::mostrarDesempenho() {
    auto lista = banco.listarRanking();

    for (auto &u : lista) {
        std::cout << "Nome: " << u.getNome()
                  << " | Pontuação: " << u.getRanking()
                  << std::endl;
    }
}