#include "microfoneCronometro.hpp"
#include <thread>
#include <chrono>

MicrofoneCronometro::MicrofoneCronometro() : microfoneAtivo(false) {}

void MicrofoneCronometro::ativar() { microfoneAtivo = true; }
void MicrofoneCronometro::desativar() { microfoneAtivo = false; } 

void MicrofoneCronometro::esperar_tempo(int tempo) {
    // Simula a espera conforme o diagrama (wait)
    std::this_thread::sleep_for(std::chrono::milliseconds(tempo * 10)); 
}