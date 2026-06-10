#include "Microfone.hpp"
#include "GerenciadorDebate.hpp"
#include "Candidato.hpp"
#include <iostream>

Microfone::Microfone()
    : id(0), ligado(false), botaoDRAtivo(false), candidatoAssociado(nullptr) {}

void Microfone::ligar() {
    if (!ligado) {
        ligado = true;
        cout << "[Microfone " << id << "]: Ligado. Som liberado." << endl;
    } else {
        cout << "[Microfone " << id << "]: Ja esta ligado." << endl;
    }
}

void Microfone::desligar() {
    if (ligado) {
        ligado = false;
        cout << "[Microfone " << id << "]: Desligado. Mudo." << endl;
    } else {
        cout << "[Microfone " << id << "]: Ja esta desligado." << endl;
    }
}

// Novo: candidato pressiona o botão DR integrado ao microfone.
// O microfone avisa o GerenciadorDebate, que decide enfileirar ou bloquear.
void Microfone::pressionarBotaoDR(
    GerenciadorDebate* ger
) {

    if (candidatoAssociado == nullptr) {
        cout << "[Microfone " << id
             << "]: Nenhum candidato associado. DR ignorado."
             << endl;
        return;
    }

    cout << "Nome do candidato: "
         << candidatoAssociado->getNome()
         << endl;

    cout << "[Microfone " << id
         << "]: Botao DR pressionado por "
         << candidatoAssociado->getNome()
         << "."
         << endl;

    botaoDRAtivo = true;

    ger->solicitarDR(candidatoAssociado);

    botaoDRAtivo = false;
}

void Microfone::setCandidatoAssociado(
    Candidato* candidato
) {

    candidatoAssociado = candidato;
}