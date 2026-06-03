#include "DiretorDebate.hpp"
#include "CandidatoBuilder.hpp"
#include "EleitorBuilder.hpp"
#include "CandidatoConcreto.hpp"
#include "Eleitor.hpp"
#include "Microfone.hpp"

DiretorDebate::DiretorDebate(CandidatoBuilder* cb, EleitorBuilder* eb)
    : candidatoBuilder(cb), eleitorBuilder(eb) {}


std::unique_ptr<CandidatoConcreto>
DiretorDebate::construirCandidato(int id, const std::string& nome, Microfone* mic) {
    return candidatoBuilder
        ->setId(id)
        ->setNome(nome)
        ->setMicrofone(mic)
        ->build();
}


std::unique_ptr<Eleitor>
DiretorDebate::construirEleitor(int id, const std::string& nome, int favorito) {
    return eleitorBuilder
        ->setId(id)
        ->setNome(nome)
        ->setFavorito(favorito)
        ->build();
}
