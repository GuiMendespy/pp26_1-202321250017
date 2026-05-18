#pragma once

class Mediador {
public:
    Mediador();
    virtual ~Mediador();

    virtual void proximaAcao() = 0;
};