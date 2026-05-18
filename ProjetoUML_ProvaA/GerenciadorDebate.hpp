#pragma once
#include <vector>
#include "Candidato.hpp"
#include "Cronometro.hpp"
#include "Logger.hpp"

class GerenciadorDebate {
    private:
        vector<Candidato*> candidatos;
        Candidato *inquiridor;
        Candidato *inquirido;
        Cronometro cronometro;
        string faseAtual;

    public:
        GerenciadorDebate();
        void sortearInquiridor();
        void definirInquirido(int id);
        void iniciarFase(int tempo);
        void registrarAcao(string acao);
        void proximaAcao();
};