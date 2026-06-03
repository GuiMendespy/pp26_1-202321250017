#pragma once
#include "EleitorBuilder.hpp"
#include "Eleitor.hpp"
#include <memory>
#include <iostream>

using namespace std;


class EleitorConcretoBuilder : public EleitorBuilder {
private:
    Eleitor* prototipoModelo;                  
    std::unique_ptr<Eleitor> eleitor;          

public:
    explicit EleitorConcretoBuilder(std::unique_ptr<Eleitor> modelo);
    ~EleitorConcretoBuilder() override;

    EleitorBuilder* setNome(const std::string& nome) override;
    EleitorBuilder* setId(int id) override;
    EleitorBuilder* setFavorito(int idCandidato) override;

    std::unique_ptr<Eleitor> build() override;
};
