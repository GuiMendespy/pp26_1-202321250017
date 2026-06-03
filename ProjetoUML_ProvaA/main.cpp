#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <memory>

#include "Observador.hpp"
#include "InterfaceCLI.hpp"
#include "Facade.hpp"
#include "CandidatoConcretoBuilder.hpp"
#include "EleitorConcretoBuilder.hpp"
#include "DiretorDebate.hpp"
#include "Eleitor.hpp"

int main() {
    system("tty > /tmp/novo_terminal.txt");
    system("xterm -e 'tty > /tmp/QuestaoProvaA.txt; sleep 10000' &");
    sleep(1);

    std::ifstream arquivoTerm("/tmp/QuestaoProvaA.txt");
    std::string caminhoTerminalNovo;
    if (arquivoTerm.is_open()) {
        std::getline(arquivoTerm, caminhoTerminalNovo);
        arquivoTerm.close();
    }

    // -----------------------------------------------------------------
    // BUILDER — infraestrutura de criação atualizada com Prototype
    // -----------------------------------------------------------------
    
    // Prototype do Candidato: cria o molde e injeta no construtor do Builder
    auto candidatoPrototipo = std::make_unique<CandidatoConcreto>();
    CandidatoConcretoBuilder candidatoBuilder(std::move(candidatoPrototipo));

    // Prototype do Eleitor: ja estava correto!
    auto eleitorPrototipo = std::make_unique<Eleitor>(0); 
    EleitorConcretoBuilder eleitorBuilder(std::move(eleitorPrototipo));

    // O Diretor continua funcionando normalmente sem saber da alteração interna
    DiretorDebate diretor(&candidatoBuilder, &eleitorBuilder);

    // -----------------------------------------------------------------
    // Microfone fictício (compartilhado pelos candidatos do debate)
    // -----------------------------------------------------------------
    Microfone microfoneDoDebate;

    // -----------------------------------------------------------------
    // Criando candidatos via Diretor + Builder
    // -----------------------------------------------------------------
    std::vector<CandidatoConcreto*> listaDeDebatedores;

    listaDeDebatedores.push_back(diretor.construirCandidato(1, "Guilherme", &microfoneDoDebate).release());
    listaDeDebatedores.push_back(diretor.construirCandidato(2, "Joao",      &microfoneDoDebate).release());
    listaDeDebatedores.push_back(diretor.construirCandidato(3, "Carol",     &microfoneDoDebate).release());
    listaDeDebatedores.push_back(diretor.construirCandidato(4, "Mariane",   &microfoneDoDebate).release());
    listaDeDebatedores.push_back(diretor.construirCandidato(5, "William",   &microfoneDoDebate).release());

    // -----------------------------------------------------------------
    // Criando eleitores via Diretor + Builder + Prototype
    // Cada eleitor já nasce com o estado-base clonado do protótipo.
    // -----------------------------------------------------------------
    std::vector<Observador*> listaDeObservadores;

    listaDeObservadores.push_back(diretor.construirEleitor(1, "Ana",    3).release());
    listaDeObservadores.push_back(diretor.construirEleitor(2, "Bruno",  1).release());
    listaDeObservadores.push_back(diretor.construirEleitor(3, "Carla",  5).release());

    // -----------------------------------------------------------------
    // Registrando os observadores no sistema de notificações (Facade)
    // -----------------------------------------------------------------
    for (Observador* obs : listaDeObservadores) {
        Facade::getInstance().registrarObservador(obs);
    }

    // -----------------------------------------------------------------
    // Interface de linha de comando
    // -----------------------------------------------------------------
    InterfaceCLI cli(listaDeDebatedores, caminhoTerminalNovo);
    cli.exibirMenu();

    // -----------------------------------------------------------------
    // Limpeza de memória
    // -----------------------------------------------------------------
    for (CandidatoConcreto* c : listaDeDebatedores) {
        delete c;
    }
    for (Observador* obs : listaDeObservadores) {
        delete obs;
    }

    return 0;
}
