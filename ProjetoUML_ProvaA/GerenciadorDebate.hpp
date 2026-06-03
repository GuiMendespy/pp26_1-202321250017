#pragma once
#include <vector>
#include <string>
#include "CandidatoConcretoBuilder.hpp" 
#include "Cronometro.hpp"
#include "Observador.hpp" 

using namespace std;

enum SubFase { PERGUNTA, RESPOSTA, REPLICA, TREPLICA, FIM_DA_RODADA };

class GerenciadorDebate {
private:
    vector<CandidatoConcreto*> candidatos;             
    vector<CandidatoConcreto*> inquiridoresRestantes; 
    CandidatoConcreto* inquiridor;                      
    CandidatoConcreto* inquirido;                      

    string nomeInquiridor;
    string nomeInquirido;
    Cronometro cronometro;
    
    vector<Observador*> observadores; 
    CandidatoConcreto* candidatoAtual;                  
    
    SubFase subFaseAtual = PERGUNTA;
    string faseAtual;

public:
    GerenciadorDebate();
    
    void setCandidatos(const vector<CandidatoConcreto*>& novosCandidatos);
    void sortearInquiridor();
    void definirInquirido(int id);
    void iniciarFase(int tempo);
    void registrarAcao(string acao);
    void proximaAcao();

    void registrarObservador(Observador* obs);
    void notificarTodos(string mensagem);
    void setCandidatoAtual(CandidatoConcreto* c);       
    void executarRodadaAutomatica(int tempoPorEtapa);
};