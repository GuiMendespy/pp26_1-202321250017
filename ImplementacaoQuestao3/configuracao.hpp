#ifndef CONFIGURACAO_H
#define CONFIGURACAO_H

class Configuracao {
private:
    int pergunta, resposta, replica, treplica;
public:
    Configuracao();
    int get_pergunta_tempo(); 
    void set_pergunta_tempo(int t);
    int get_resposta_tempo(); 
    void set_resposta_tempo(int t); 
    int get_replica_tempo(); 
    void set_replica_tempo(int t); 
    int get_treplica_tempo();
    void set_treplica_tempo(int t); 
};
#endif