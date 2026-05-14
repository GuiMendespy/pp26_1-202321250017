#include "facade.hpp"

#include <ctime>

int main() {
    srand(time(0));
    Facade* facade = Facade::get_instance(); 

    facade->cadastrar_politico("Candidato 1");
    facade->cadastrar_politico("Candidato 2");

    int tempos[] = {10, 20, 10}; 
    facade->configuracao_tempos(tempos);

    facade->sortear_inquiridor();
    facade->escolher_inquirido("Candidato 2");
    facade->iniciar_debate(); 

    return 0;
}