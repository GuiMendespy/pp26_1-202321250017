#ifndef MEDIADOR_H
#define MEDIADOR_H

class Configuracao; // Forward declaration

class Mediador {
public:
    virtual void debate(Configuracao& config) = 0; 
    virtual ~Mediador() {}
};
#endif