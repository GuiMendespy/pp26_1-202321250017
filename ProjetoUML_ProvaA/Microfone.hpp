#pragma once

class Microfone {
    private:
        int id;
        bool ligado;

    public:
        Microfone();
        void ligar();
        void desligar();
};