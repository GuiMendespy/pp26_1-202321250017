#pragma once
#include <string>
#include <memory>

class Eleitor;


class EleitorBuilder {
public:
    virtual ~EleitorBuilder() = default;

    virtual EleitorBuilder* setNome(const std::string& nome) = 0;
    virtual EleitorBuilder* setId(int id) = 0;
    virtual EleitorBuilder* setFavorito(int idCandidato) = 0;

    virtual std::unique_ptr<Eleitor> build() = 0;
};
