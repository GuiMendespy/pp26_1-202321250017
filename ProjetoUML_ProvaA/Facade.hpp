#pragma once
#include "Logger.hpp"
#include <vector>
#include "Observador.hpp"
using namespace std;

class GerenciadorDebate; 
class CandidatoConcreto; 

class Facade {
    private:
        static Facade instance;
        GerenciadorDebate* gerenciador;
        CandidatoConcreto* candidato;
        Logger logger;
        Facade();

    public:
        Facade(const Facade&) = delete;
        void operator=(const Facade&) = delete;
        static Facade& getInstance();
        
        void configurarDebate(vector<CandidatoConcreto*> candidatos, int tempos);
        
        void registrarObservador(Observador* obs);
        void sortearInquiridor();
        void definirInquirido(int idCandidato);
        
        void iniciarDebate();
        void avancarEtapa();
        void fincalizarDebate();
        Logger& getLogger();
        void iniciarRodadaAutomatica(int tempoPorEtapa);
};