#include "EleitorConcretoBuilder.hpp"

EleitorConcretoBuilder::EleitorConcretoBuilder(std::unique_ptr<Eleitor> modelo) {
    prototipoModelo = modelo.release();          
    eleitor.reset(prototipoModelo->clonar());    
}

EleitorConcretoBuilder::~EleitorConcretoBuilder() {
    delete prototipoModelo;                     
}

EleitorBuilder* EleitorConcretoBuilder::setNome(const std::string& nome) {
    eleitor->nome = nome;
    return this;
}

EleitorBuilder* EleitorConcretoBuilder::setId(int id) {
    eleitor->candidatoId = id;
    return this;
}

EleitorBuilder* EleitorConcretoBuilder::setFavorito(int idCandidato) {
    eleitor->idCandidatoFavorito = idCandidato;
    return this;
}

std::unique_ptr<Eleitor> EleitorConcretoBuilder::build() {
    std::unique_ptr<Eleitor> resultado = std::move(eleitor);

    std::cout << "[BUILDER] Eleitor lapidado e pronto para o debate." << std::endl;
    
    eleitor.reset(static_cast<Eleitor*>(prototipoModelo->clonar()));

    return resultado;
}
