#pragma once
#include <string>
#include <memory>


class CandidatoBuilder;
class EleitorBuilder;


class CandidatoConcreto;
class Eleitor;
class Microfone;

class DiretorDebate {
private:
    CandidatoBuilder* candidatoBuilder;
    EleitorBuilder* eleitorBuilder;

public:
    // Construtor que injeta as dependências das interfaces abstratas dos builders
    DiretorDebate(CandidatoBuilder* cb, EleitorBuilder* eb);

    // Orquestra a ordem de montagem de um candidato
    std::unique_ptr<CandidatoConcreto> construirCandidato(int id, const std::string& nome, Microfone* mic);

    // Orquestra a ordem de montagem de um eleitor
    std::unique_ptr<Eleitor> construirEleitor(int id, const std::string& nome, int favorito);
};