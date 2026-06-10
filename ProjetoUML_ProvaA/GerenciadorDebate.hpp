#pragma once
#include <vector>
#include <queue>
#include <string>
#include "CandidatoConcretoBuilder.hpp"
#include "Cronometro.hpp"
#include "Observador.hpp"
#include "SubFase.hpp"
#include "Microfone.hpp"

using namespace std;

class GerenciadorDebate {
private:
    vector<CandidatoConcreto*> candidatos;
    vector<CandidatoConcreto*> inquiridoresRestantes;
    Candidato* inquiridor;
    Candidato* inquirido;

    string nomeInquiridor;
    string nomeInquirido;
    Cronometro cronometro;

    vector<Observador*> observadores;
    Candidato* candidatoAtual;

    // Padrão State: subFaseAtual agora é um ponteiro para SubFase
    SubFase* subFaseAtual;
    string faseAtual;
    Microfone microfoneAtual;

    // Direito de Resposta
    queue<Candidato*> filaDR;
    bool drBloqueado;

public:
    GerenciadorDebate();
    ~GerenciadorDebate();

    // Configuração
    void setCandidatos(const vector<CandidatoConcreto*>& novosCandidatos);
    void sortearInquiridor();
    void definirInquirido(int id);
    void iniciarFase(int tempo);

    // Execução do debate
    void proximaAcao(int tempoPorEtapa);
    void executarRodadaAutomatica(int tempoPorEtapa);

    // Observer
    void registrarObservador(Observador* obs);
    void notificarTodos(string mensagem);

    // Getters usados pelos estados concretos de SubFase
    string getNomeInquiridor() const { return nomeInquiridor; }
    string getNomeInquirido()  const { return nomeInquirido; }
    Cronometro& getCronometro()      { return cronometro; }
    queue<Candidato*>& getFilaDR() { return filaDR; }
    bool isDRBloqueado() const       { return drBloqueado; }

    // Setters usados pelos estados concretos de SubFase
    void setSubFase(SubFase* novaFase);
    void setCandidatoAtual(Candidato* c);
    void setCandidatoAtualPorNome(const string& nome);
    void setDRBloqueado(bool valor)  { drBloqueado = valor; }

    // Direito de Resposta
    void solicitarDR(Candidato* candidato);
    void solicitarDRPorId(int candidatoId); // chamado pela Facade
    void simularPedidosDR();

    // Utilitários
    void registrarAcao(string acao);
    void resetarRodada();
};
