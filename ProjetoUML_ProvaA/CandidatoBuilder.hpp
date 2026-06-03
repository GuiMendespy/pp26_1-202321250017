#pragma once
#include <string>
#include <memory>

class Microfone;
class CandidatoConcreto;

class CandidatoBuilder {
public:
    virtual ~CandidatoBuilder() = default;

    virtual CandidatoBuilder* setNome(const std::string& nome) = 0;
    virtual CandidatoBuilder* setId(int id) = 0;
    virtual CandidatoBuilder* setMicrofone(Microfone* m) = 0;

    virtual std::unique_ptr<CandidatoConcreto> build() = 0;
};