#ifndef MICROFONECRONOMETRO_H
#define MICROFONECRONOMETRO_H

class MicrofoneCronometro {
private:
    bool microfoneAtivo; 
public:
    MicrofoneCronometro();
    void ativar();
    void desativar();
    void esperar_tempo(int tempo); 
};
#endif