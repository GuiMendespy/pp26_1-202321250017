#pragma once
#include "SubFase.hpp"

// Estado concreto responsavel por processar as defesas de Direito de Resposta.
// Enquanto este estado esta ativo, novos pedidos de DR sao bloqueados
// para evitar ciclos infinitos.

class FimDaRodada;

class FaseDefesaDR : public SubFase {
public:
    void processarFase(GerenciadorDebate* ger, int tempoPorEtapa) override;
    std::string getFase() const override { return "DefesaDR"; }
};
