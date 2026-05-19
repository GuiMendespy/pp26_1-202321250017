#pragma once
#include <vector>
#include <string>
#include "Candidato.hpp"
#include "Cronometro.hpp"
#include "Observador.hpp" 

using namespace std;

enum SubFase { PERGUNTA, RESPOSTA, REPLICA, TREPLICA, FIM_DA_RODADA };

class GerenciadorDebate {
private:
    vector<Candidato*> candidatos;
    vector<Candidato*> inquiridoresRestantes; 
    Candidato* inquiridor;
    Candidato* inquirido;
    Cronometro cronometro;

    string nomeInquiridor;
    string nomeInquirido;
    
    vector<Observador*> observadores; 
    Candidato* candidatoAtual;
    
    SubFase subFaseAtual = PERGUNTA;
    string faseAtual;

public:
    GerenciadorDebate();
    
    void setCandidatos(const vector<Candidato*>& novosCandidatos);
    void sortearInquiridor();
    void definirInquirido(int id);
    void iniciarFase(int tempo);
    void registrarAcao(string acao);
    void proximaAcao();

    void registrarObservador(Observador* obs);
    void notificarTodos(string mensagem);
    void setCandidatoAtual(Candidato* c);
    void executarRodadaAutomatica(int tempoPorEtapa);
};