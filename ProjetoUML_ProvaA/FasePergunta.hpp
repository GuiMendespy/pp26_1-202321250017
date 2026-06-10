#pragma once
#include "SubFase.hpp"

class FaseResposta;

class FasePergunta : public SubFase {
public:
    void processarFase(GerenciadorDebate* ger, int tempoPorEtapa) override;
    std::string getFase() const override { return "Pergunta"; }
};
