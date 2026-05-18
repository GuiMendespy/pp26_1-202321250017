#include "Logger.hpp"
#include <iostream>

Logger::Logger() {
    // O vetor 'historicoLogs' se inicializa vazio automaticamente
}

void Logger::registrar(std::string mensagem) {
    // 1. Guarda a mensagem no histórico em memória
    this->logs.push_back(mensagem);
    
    // 2. Opcional: Mostra na tela imediatamente também (se você quiser acompanhar em tempo real)
    std::cout << "[LOG CAPTURADO]: " << mensagem << std::endl;
}

void Logger::gerarRelatorio() {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "       RELATÓRIO GERAL DO DEBATE         " << std::endl;
    std::cout << "==========================================" << std::endl;
    
    if (this->logs.empty()) {
        std::cout << "Nenhum log foi registrado até o momento." << std::endl;
    } else {
        // Percorre o vetor exibindo cada linha armazenada
        for (size_t i = 0; i < this->logs.size(); ++i) {
            std::cout << "[" << i + 1 << "] " << this->logs[i] << std::endl;
        }
    }
    
    std::cout << "==========================================\n" << std::endl;
}