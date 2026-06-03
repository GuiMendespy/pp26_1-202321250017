#pragma once
#include <string>
#include <memory>
#include "Observador.hpp"
#include "Prototipo.hpp"

class EleitorConcretoBuilder;


class Eleitor : public Observador, public Prototipo {
private:
    int idCandidatoFavorito;
    std::string nome;
    int candidatoId;

    friend class EleitorConcretoBuilder;

public:
    explicit Eleitor(int idFavorito);

    Eleitor* clonar() const override;          

    void atualizar(std::string msg) override;

    int getCandidatoId() override;
    std::string exibirNotificacao() const;
};
