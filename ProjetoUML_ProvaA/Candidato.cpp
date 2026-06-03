#include "Candidato.hpp"
#include <iostream>

Candidato::Candidato(string nomeInicial, Microfone* m) : id(0), jaPerguntou(false) {
    this->nome = nomeInicial;
    if (m != nullptr) {
        this->microfone = *m;
    }
}

Candidato::Candidato(const Candidato& outro) {
    this->id = outro.id;
    this->nome = outro.nome;
    this->jaPerguntou = outro.jaPerguntou;
    this->microfone = outro.microfone;
    
    std::cout << "[PROTOTYPE] Estrutura base de Candidato clonada com sucesso." << std::endl;
}

void Candidato::marcarComoInquiridor() {
    this->jaPerguntou = true;
    this->microfone.ligar();
    std::cout << "[Candidato " << this->nome << "]: Definido como inquiridor da rodada e microfone ativado." << std::endl;
}

string Candidato::getNome() const { return this->nome; }
int Candidato::getId() const { return this->id; }