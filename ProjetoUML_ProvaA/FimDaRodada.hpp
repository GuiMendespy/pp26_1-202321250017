#pragma once
#include "SubFase.hpp"

class FasePergunta;

class FimDaRodada : public SubFase {
public:
    void processarFase(GerenciadorDebate* ger, int tempoPorEtapa) override;
    std::string getFase() const override { return "FimDaRodada"; }
};
