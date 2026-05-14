#include "configuracao.hpp"

Configuracao::Configuracao() : pergunta(30), resposta(60), replica(30), treplica(15) {}
int Configuracao::get_pergunta_tempo() { return pergunta; }
void Configuracao::set_pergunta_tempo(int t) { pergunta = t; }
int Configuracao::get_resposta_tempo() { return resposta; }
void Configuracao::set_resposta_tempo(int t) { resposta = t; }
int Configuracao::get_replica_tempo() { return replica; }
void Configuracao::set_replica_tempo(int t) { replica = t; }
int Configuracao::get_treplica_tempo() { return treplica; }
void Configuracao::set_treplica_tempo(int t) { treplica = t; }