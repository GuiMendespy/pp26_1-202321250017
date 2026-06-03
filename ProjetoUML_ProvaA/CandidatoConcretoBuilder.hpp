#pragma once
#include "CandidatoBuilder.hpp"
#include <memory>
#include "Microfone.hpp"
#include "CandidatoConcreto.hpp"

class CandidatoConcretoBuilder : public CandidatoBuilder {
private:
    std::unique_ptr<CandidatoConcreto> prototipoModelo;     // O molde salvo
    std::unique_ptr<CandidatoConcreto> candidato;            // O objeto em modificação

public:
    CandidatoConcretoBuilder(std::unique_ptr<CandidatoConcreto> modelo);
    virtual ~CandidatoConcretoBuilder() = default;

    CandidatoBuilder* setNome(const std::string& nome) override;
    CandidatoBuilder* setId(int id) override;
    CandidatoBuilder* setMicrofone(Microfone* m) override;

    std::unique_ptr<CandidatoConcreto> build() override;
};