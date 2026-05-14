#ifndef FACADE_H
#define FACADE_H
#include "mediadorDebate.hpp"
#include "configuracao.hpp"
#include "gerenciadorPolitico.hpp"
#include "logger.hpp"

class Facade {
private:
    static Facade* instance; 
    MediadorDebate* mediador_debate;
    Configuracao config; 
    GerenciadorPoliticos gerencia_politicos; 
    Logger* logger; 
    Facade(); 

public:
    static Facade* get_instance(); 
    void configuracao_tempos(int tempos[3]); 
    void sortear_inquiridor(); 
    void escolher_inquirido(std::string nome); 
    void iniciar_debate(); 
    void cadastrar_politico(std::string nome);
};
#endif