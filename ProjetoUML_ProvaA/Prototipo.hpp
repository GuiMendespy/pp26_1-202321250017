#pragma once
#include <memory>


class Prototipo {
public:
    virtual ~Prototipo() = default;
    virtual Prototipo* clonar() const = 0;
};
