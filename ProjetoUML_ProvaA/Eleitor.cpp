#include "Eleitor.hpp"
#include <iostream>

// Construtor: Inicializa os atributos com valores padrão seguros
Eleitor::Eleitor() : id(0), nome(""), candidatoId(0) {
    // Se no seu hpp você adicionar o atributo 'ultimaMensagem', 
    // pode inicializá-lo aqui também: : id(0), nome(""), candidatoId(0), ultimaMensagem("")
}

// Recebe a notificação do debate/sistema (Geralmente acionado pelo padrão Observer)
void Eleitor::atualizar(string msg) {
    // Armazena a mensagem recebida para poder ser exibida depois pelo método exibirNotificacao
    // Nota: Para isso funcionar perfeitamente, adicione 'string ultimaMensagem;' nos atributos privados do seu .hpp
    this->nome = msg; // Se você não quiser criar outro atributo, pode usar temporariamente aqui, mas o ideal é guardar em uma variável própria para mensagens.
}

// Retorna o ID do candidato em quem este eleitor pretende votar ou apoiar
int Eleitor::getCandidatoId() {
    return this->candidatoId;
}

// Retorna a última notificação que o eleitor recebeu para ser mostrada na tela
string Eleitor::exibirNotificacao() {
    // Retorna o texto formatado ou a variável onde a mensagem foi salva
    return "Notificação para o Eleitor: " + this->nome; 
}