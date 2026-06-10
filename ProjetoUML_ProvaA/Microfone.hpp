#pragma once
#include <string>

class GerenciadorDebate; // forward declaration
class Candidato;

class Microfone {
private:
    int id;
    bool ligado;
    bool botaoDRAtivo;                  // novo: indica se o botão DR foi pressionado
    Candidato* candidatoAssociado; // novo: dono do microfone

public:
    Microfone();

    void ligar();
    void desligar();

    // Novo: aciona o Direito de Resposta notificando o GerenciadorDebate
    void pressionarBotaoDR(GerenciadorDebate* ger);

    Candidato* getCandidatoAssociado() const  { return candidatoAssociado; }

    void setId(int novoId) { id = novoId; }
    int  getId()     const { return id; }
    bool isLigado()  const { return ligado; }
    void setCandidatoAssociado(Candidato* candidato);
};
