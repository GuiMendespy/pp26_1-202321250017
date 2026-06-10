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
    void avancarEtapa(int tempoPorEtapa);
    void fincalizarDebate();

    // Novo: encaminha solicitação de DR ao GerenciadorDebate
    void solicitarDR(int candidatoId);

    Logger& getLogger();
    void iniciarRodadaAutomatica(int tempoPorEtapa);
};
