#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
#include "Candidato.hpp"
#include "Observador.hpp"  // 1º: Avisa a main o que é a Interface mãe
#include "Eleitor.hpp"     // 2º: Avisa a main o que é a classe filha
#include "InterfaceCLI.hpp"
#include "Facade.hpp"

int main() {
    // 1. Criando um arquivo temporário para o novo terminal nos dizer quem ele é
    system("tty > /tmp/novo_terminal.txt"); 
    
    // 2. Abre uma nova janela de terminal 
    system("xterm -e 'tty > /tmp/QuestaoProvaA.txt; sleep 10000' &");
    sleep(1);

    // 3. Lê o endereço do novo terminal
    std::ifstream arquivoTerm("/tmp/QuestaoProvaA.txt");
    std::string caminhoTerminalNovo;
    if (arquivoTerm.is_open()) {
        std::getline(arquivoTerm, caminhoTerminalNovo);
        arquivoTerm.close();
    }

    // 4. Criando os 10 candidatos manualmente na memória
    Candidato* c1 = new Candidato("Guilherme"); 
    Candidato* c2 = new Candidato("Joao");
    Candidato* c3 = new Candidato("Carol");
    Candidato* c4 = new Candidato("Mariane");
    Candidato* c5 = new Candidato("William");

    // 5. Agrupando os candidatos no vetor (vector)
    std::vector<Candidato*> listaDeDebatedores;
    listaDeDebatedores.push_back(c1); 
    listaDeDebatedores.push_back(c2); 
    listaDeDebatedores.push_back(c3); 
    listaDeDebatedores.push_back(c4);
    listaDeDebatedores.push_back(c5); 

    // ======================================================================
    // 6. ADICIONANDO OS OBSERVADORES (ELEITORES)
    // ======================================================================
    // Criamos um vetor separado para gerenciar a memória dos observadores depois
    std::vector<Observador*> listaDeObservadores;

    // Criando eleitores e vinculando aos seus candidatos favoritos (Ex: ID ou ponteiro)
    // Se o seu construtor de Eleitor pedir o ID do candidato, mude o parâmetro abaixo
    Observador* e1 = new Eleitor(1); // Eleitor focado no candidato do índice 0 (c1)
    Observador* e2 = new Eleitor(2); // Eleitor focado no candidato do índice 1 (c2)
    Observador* e3 = new Eleitor(3); // Eleitor focado no candidato do índice 5 (c6)

    listaDeObservadores.push_back(e1);
    listaDeObservadores.push_back(e2);
    listaDeObservadores.push_back(e3);

    // REGISTRO REAL NO SISTEMA: Passamos os observadores para a Facade guardar no Gerenciador
    for (Observador* obs : listaDeObservadores) {
        Facade::getInstance().registrarObservador(obs);
    }
    // ======================================================================

    // 7. Dispara a interface para o usuário começar a interagir e sortear
    InterfaceCLI cli(listaDeDebatedores, caminhoTerminalNovo);
    cli.exibirMenu();

    // 8. Limpeza de memória dos CANDIDATOS ao fechar o programa
    for (Candidato* c : listaDeDebatedores) {
        delete c;
    }

    // 9. Limpeza de memória dos OBSERVADORES (Evita Memory Leak)
    for (Observador* obs : listaDeObservadores) {
        delete obs;
    }

    return 0;
}