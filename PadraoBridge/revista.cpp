#include "revista.hpp"

revista::revista(implementador* i) : publicacao(i) {}

string revista::getArtigo(){
        return "getArtigo -> Sucesso!!";
}
string revista::getTitulo(){
        return "getTitulo -> Sucesso!!";
}
string revista::getAutor(int id){
        return "Retorna autor";

}