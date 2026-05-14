#include "inquiridorColaborador.hpp"

InquiridorColaborador::InquiridorColaborador(std::string n) : PoliticoColaborador(n) {}
PoliticoColaborador* InquiridorColaborador::escolher_inquirido(PoliticoColaborador* p) {
    return p; 
}