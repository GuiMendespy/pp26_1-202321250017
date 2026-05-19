#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
#include "Candidato.hpp"
#include "Observador.hpp"  
#include "Eleitor.hpp"     
#include "InterfaceCLI.hpp"
#include "Facade.hpp"

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

    Candidato* c1 = new Candidato("Guilherme"); 
    Candidato* c2 = new Candidato("Joao");
    Candidato* c3 = new Candidato("Carol");
    Candidato* c4 = new Candidato("Mariane");
    Candidato* c5 = new Candidato("William");

    std::vector<Candidato*> listaDeDebatedores;
    listaDeDebatedores.push_back(c1); 
    listaDeDebatedores.push_back(c2); 
    listaDeDebatedores.push_back(c3); 
    listaDeDebatedores.push_back(c4);
    listaDeDebatedores.push_back(c5); 

    
    std::vector<Observador*> listaDeObservadores;

    Observador* e1 = new Eleitor(1); 
    Observador* e2 = new Eleitor(2); 
    Observador* e3 = new Eleitor(3); 

    listaDeObservadores.push_back(e1);
    listaDeObservadores.push_back(e2);
    listaDeObservadores.push_back(e3);

    for (Observador* obs : listaDeObservadores) {
        Facade::getInstance().registrarObservador(obs);
    }

    InterfaceCLI cli(listaDeDebatedores, caminhoTerminalNovo);
    cli.exibirMenu();

    for (Candidato* c : listaDeDebatedores) {
        delete c;
    }

    for (Observador* obs : listaDeObservadores) {
        delete obs;
    }

    return 0;
}