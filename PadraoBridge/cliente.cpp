#include <iostream>
#include "cliente.hpp"
#include "livro.hpp"
#include "revista.hpp"
#include "publicacaoImpBD.hpp"
#include "publicacaoXML.hpp"

using namespace std;

void cliente::executar() {

    implementador* bd = new publicacaoImpBD();
    implementador* xml = new publicacaoXML();

    livro lvbd(bd);
    revista rvbd(bd);

    livro lvxml(xml);
    revista rvxml(xml);

    cout << "Resultados de Livros em ImpBD" << endl;
    cout << lvbd.getISBN() << endl;
    cout << lvbd.getAutor() << endl;
    cout << lvbd.getTitulo() << endl;
    cout << lvbd.obterDados("Livro em ImpBD") << endl;

    cout << endl;
    cout << "Resultados de Livros em XML" << endl;

    cout << lvxml.getISBN() << endl;
    cout << lvxml.getAutor() << endl;
    cout << lvxml.getTitulo() << endl;
    cout << lvxml.obterDados("Livro em XML") << endl;

    cout << endl;
    cout << "Resultados de Revistas em ImpBD" << endl;

    cout << rvbd.getArtigo() << endl;
    cout << rvbd.getAutor(0) << endl;
    cout << rvbd.getTitulo() << endl;
    cout << rvbd.obterDados("Revista em ImpBD") << endl;

    cout << endl;
    cout << "Resultados de Revistas em XML" << endl;

    cout << rvxml.getArtigo() << endl;
    cout << rvxml.getAutor(0) << endl;
    cout << rvxml.getTitulo() << endl;
    cout << rvxml.obterDados("Revista em XML") << endl;

    delete bd;
    delete xml;
}