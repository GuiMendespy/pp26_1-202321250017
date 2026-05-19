#include "Candidato.hpp"
#include <iostream>

// CORREÇÃO: Inicializa o id com 0 (ou um valor seguro) e jaPerguntou como false
Candidato::Candidato(string nomeInicial) : id(id), jaPerguntou(false) {
    this->nome = nomeInicial;
    // Removidas as linhas soltas "this->id;" que não tinham efeito
}

// Altera o estado do candidato para indicar que ele já fez a sua pergunta no turno
void Candidato::marcarComoInquiridor() {
    this->jaPerguntou = true;
    
    // Abre o microfone do candidato usando o objeto interno
    this->microfone.ligar();
    
    std::cout << "[Candidato " << this->nome << "]: Definido como inquiridor da rodada e microfone ativado." << std::endl;
}

// CORREÇÃO: Implementação limpa do método Get para retornar o nome correto
string Candidato::getNome() const {
    return this->nome;
}

int Candidato::getId() const{
    return this->id;
}