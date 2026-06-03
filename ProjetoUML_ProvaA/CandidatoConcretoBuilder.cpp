#include "CandidatoConcretoBuilder.hpp"
#include "CandidatoConcreto.hpp" 
#include "Microfone.hpp"         
#include <iostream>

CandidatoConcretoBuilder::CandidatoConcretoBuilder(std::unique_ptr<CandidatoConcreto> modelo) {
    this->prototipoModelo = std::move(modelo);
    
    // ====== AJUSTADO: Transforma o Prototipo* de volta no tipo correto do Builder ======
    this->candidato = std::unique_ptr<CandidatoConcreto>(static_cast<CandidatoConcreto*>(prototipoModelo->clonar()));
}

CandidatoBuilder* CandidatoConcretoBuilder::setNome(const std::string& nome) {
    candidato->nome = nome;
    return this;
}

CandidatoBuilder* CandidatoConcretoBuilder::setId(int id) {
    candidato->id = id;
    return this;
}

CandidatoBuilder* CandidatoConcretoBuilder::setMicrofone(Microfone* m) {
    if (m != nullptr) {
        candidato->microfone = *m; 
    }
    return this;
}

std::unique_ptr<CandidatoConcreto> CandidatoConcretoBuilder::build() {
    std::unique_ptr<CandidatoConcreto> resultado = std::move(candidato);
    
    std::cout << "[BUILDER] Candidato '" << resultado->getNome() 
              << "' (ID: " << resultado->getId() 
              << ") lapidado e pronto para o debate." << std::endl;
              
    // ====== AJUSTADO: Reseta clonando o molde fixo ======
    candidato = std::unique_ptr<CandidatoConcreto>(static_cast<CandidatoConcreto*>(prototipoModelo->clonar()));
    
    return resultado;
}