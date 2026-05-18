#include "GerenciadorDebate.hpp"
#include <iostream>
#include <random>    // Necessário para o sorteio aleatório robusto
#include <stdexcept> // Para tratamento de erros/exceções

// Sorteia aleatoriamente um dos candidatos da lista para ser o inquiridor
void GerenciadorDebate::sortearInquiridor() {
    if (candidatos.empty()) {
        std::cout << "[Erro]: Não há candidatos cadastrados para sortear." << std::endl;
        return;
    }

    // Configura o gerador de números aleatórios moderno do C++
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, candidatos.size() - 1);

    int indiceSorteado = distrib(gen);
    this->inquiridor = candidatos[indiceSorteado];
    
    this->registrarAcao("Um novo inquiridor foi sorteado.");
}

// Define quem será o candidato respondendo à pergunta com base em uma busca por ID/Índice
void GerenciadorDebate::definirInquirido(int id) {
    // Validação simples: tratando o ID recebido como o índice do vetor
    if (id >= 0 && id < static_cast<int>(candidatos.size())) {
        this->inquirido = candidatos[id];
        this->registrarAcao("Candidato inquirido foi definido.");
    } else {
        std::cout << "[Erro]: ID de candidato inválido." << std::endl;
    }
}

// Modifica a fase atual do debate e aciona o cronômetro com o tempo estipulado
void GerenciadorDebate::iniciarFase(int tempo) {
    this->faseAtual = "Fase Ativa";
    this->cronometro.iniciar(tempo);
    this->registrarAcao("Uma nova fase de debate foi iniciada.");
}

// Encaminha eventos importantes para o Singleton do Logger salvar/exibir
void GerenciadorDebate::registrarAcao(string acao) {
    // Como Logger é Singleton, chamamos o getInstance() em vez de usar um atributo local
    Logger::getInstancia()->log("[GerenciadorDebate] " + acao);
}

// Avança para a próxima etapa interna do fluxo de perguntas e respostas
void GerenciadorDebate::proximaAcao() {
    std::cout << "Avançando para a próxima ação do fluxo de debate..." << std::endl;
    // Aqui você implementará as transições de estado do seu debate
    // Ex: Se o tempo acabou, finaliza a fala, limpa inquiridor/inquirido e avança.
    this->cronometro.finalizarTempo();
}