#include "Candidato.hpp"
#include <iostream>

Candidato::Candidato(
    string nomeInicial,
    Microfone* m
)
    : id(0),
      jaPerguntou(false)
{
    nome = nomeInicial;

    if (m != nullptr) {
        microfone = *m;
    }

    // Sempre associa o dono do microfone
    microfone.setCandidatoAssociado(this);
}

Candidato::Candidato(const Candidato& outro) {


    this->id = outro.id;
    this->nome = outro.nome;
    this->jaPerguntou = outro.jaPerguntou;
    this->microfone = outro.microfone;

    microfone.setCandidatoAssociado(this);
}

void Candidato::marcarComoInquiridor() {
    this->jaPerguntou = true;
    this->microfone.ligar();
    std::cout << "[Candidato " << this->nome << "]: Definido como inquiridor da rodada e microfone ativado." << std::endl;
}

string Candidato::getNome() const { return this->nome; }
int Candidato::getId() const { return this->id; }

Microfone& Candidato::getMicrofone() {
    return microfone;
}