#pragma once
#include <string>
#include "Observador.hpp"
using namespace std;

class Eleitor : public Observador{
    private:
        int idCandidatoFavorito;
        string nome;
        int candidatoId;
    public:
        Eleitor(int idFavorito);
        void atualizar(string msg);
        int getCandidatoId();
        string exibirNotificacao();
};