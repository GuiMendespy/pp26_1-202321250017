#include "livro.hpp"

livro::livro(implementador* i) : publicacao(i) {}

string livro::getISBN(){
    return "getISBN -> Sucesso!!";
}
string livro::getTitulo(){
    return "getTitulo -> Sucesso!!";
}
string livro::getAutor(){
    return "Retorna autor";
}
