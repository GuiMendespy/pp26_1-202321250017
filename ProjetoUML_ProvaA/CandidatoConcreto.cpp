#include "CandidatoConcreto.hpp"
#include <algorithm> // Necessário para o std::remove

// Construtor: chama o construtor da classe base (Candidato)
CandidatoConcreto::CandidatoConcreto() : Candidato() {
    // Inicializações específicas do CandidatoConcreto, se houver
}

// Adiciona um observador à lista se ele não for nulo
void CandidatoConcreto::registrar(Observador* o) {
    if (o != nullptr) {
        observadores.push_back(o);
    }
}

// Remove o observador específico da lista (padrão erase-remove idiom do C++)
void CandidatoConcreto::remover(Observador* o) {
    observadores.erase(std::remove(observadores.begin(), observadores.end(), o), observadores.end());
}

// Percorre a lista e avisa todos os observadores cadastrados
void CandidatoConcreto::notificar() {
    for (Observador* obs : observadores) {
        if (obs != nullptr) {
            obs->atualizar(); // Dispara o método virtual da interface Observador
        }
    }
}

// Altera o estado do candidato e avisa as interfaces de visualização
void CandidatoConcreto::marcarComoInquisidor() {
    // Aqui você pode adicionar uma variável booleana (ex: 'this->ehInquisidor = true;') 
    // se precisar salvar esse estado dentro da classe para usar depois.
    
    // Regra do padrão Observer: sempre que o estado muda, notificamos os observadores
    this->notificar();
}