#pragma once
#include "SubFase.hpp"

class FaseTreplica;

class FaseReplica : public SubFase {
public:
    void processarFase(GerenciadorDebate* ger, int tempoPorEtapa) override;
    std::string getFase() const override { return "Replica"; }
};
