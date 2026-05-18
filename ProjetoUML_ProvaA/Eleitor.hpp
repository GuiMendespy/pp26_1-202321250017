#pragma once
#include <string>
using namespace std;

class Eleitor {
    private:
        int id;
        string nome;
        int candidatoId;
    public:
        Eleitor();
        void atualizar(string msg);
        int getCandidatoId();
        string exibirNotificacao();
};