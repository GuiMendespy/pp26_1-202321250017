#pragma once
#include <string>

class GerenciadorDebate; // forward declaration

class SubFase {
public:
    virtual ~SubFase() = default;
    virtual void processarFase(GerenciadorDebate* ger, int tempoPorEtapa) = 0;
    virtual std::string getFase() const = 0;
};
