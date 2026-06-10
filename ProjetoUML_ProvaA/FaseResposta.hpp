#pragma once
#include "SubFase.hpp"

class FaseReplica;

class FaseResposta : public SubFase {
public:
    void processarFase(GerenciadorDebate* ger, int tempoPorEtapa) override;
    std::string getFase() const override { return "Resposta"; }
};
