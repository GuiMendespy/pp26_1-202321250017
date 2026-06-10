#pragma once
#include "SubFase.hpp"

class FaseDefesaDR;
class FimDaRodada;

class FaseTreplica : public SubFase {
public:
    void processarFase(GerenciadorDebate* ger, int tempoPorEtapa) override;
    std::string getFase() const override { return "Treplica"; }
};
