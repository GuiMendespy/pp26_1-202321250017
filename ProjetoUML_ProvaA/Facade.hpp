#pragma once
#include "GerenciadorDebate.hpp"
#include "Candidato.hpp"
#include "Logger.hpp"
#include <vector>
using namespace std;

class Facade {
    private:
        static Facade instance;
        GerenciadorDebate gerenciador;
        Logger logger;
        Facade();

    public:
        Facade(const Facade&) = delete;
        void operator=(const Facade&) = delete;
        static Facade& getInstance();
        void configurarDebate(vector<Candidato*> candidato, int tempos);
        void sortearInquiridor();
        void definirInquirido(int idCandidato);
        void iniciarDebate();
        void avancarEtapa();
        void fincalizarDebate();
        Logger& getLogger();
};