#include "terminal.hpp"
#include "Facade.hpp"
#include <iostream>

using namespace std;

void Terminal::iniciar() {
    char resposta;

    cout << "=================================\n";
    cout << " SEJA BEM VINDO AO PAPAPILHA\n";
    cout << "=================================\n";
    cout << "Você já possui cadastro? (S/N): ";
    cin >> resposta;

    if (resposta == 'S' || resposta == 's') {
        if (telaLogin()) {
            menuPrincipal();
        } else {
            cout << "Falha no login!\n";
        }
    } else {
        telaCadastro();
        cout << "\nCadastro realizado! Faça login agora.\n";
        if (telaLogin()) {
            menuPrincipal();
        }
    }
}

// ================= LOGIN =================
bool Terminal::telaLogin() {
    double matric;
    string senha;

    cout << "\n=== LOGIN ===\n";

    cout << "Matrícula: ";
    cin >> matric;

    cin.ignore(); // IMPORTANTE

    cout << "Senha: ";
    getline(cin, senha);

    if (Fachada::getInstance()->autenticar(matric, senha)) {
        cout << "Login realizado com sucesso!\n";
        return true;
    }

    return false;
}

// ================= CADASTRO =================
void Terminal::telaCadastro() {
    string nome, senha;
    double matric;

    cout << "\n=== CADASTRO ===\n";

    cin.ignore(); // LIMPA buffer antes do getline

    cout << "Nome: ";
    getline(cin, nome);

    cout << "Matrícula: ";
    cin >> matric;

    cin.ignore(); // LIMPA buffer antes da senha

    cout << "Senha: ";
    getline(cin, senha);


    Fachada::getInstance()->cadastrar(nome, matric, senha);
}

// ================= MENU =================
void Terminal::menuPrincipal() {
    int opcao;

    do {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1 - Cadastrar novo usuário\n";
        cout << "2 - Descartar Pilha\n";
        cout << "3 - Ver Ranking\n";
        cout << "4 - Ver Desempenho\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                telaCadastro();
                break;
            case 2:
                telaDescarte();
                break;
            case 3:
                telaRanking();
                break;
            case 4:
                Fachada::getInstance()->mostrarDesempenho();
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }

    } while(opcao != 0);
}

// ================= DESCARTE =================
void Terminal::telaDescarte() {
    int tipo;

    cout << "\n=== DESCARTE DE PILHAS ===\n";
    cout << "1 - AA\n";
    cout << "2 - AAA\n";
    cout << "3 - 9V\n";
    cout << "Escolha o tipo: ";
    cin >> tipo;

    cout << "Pilha descartada com sucesso!\n";

    // Aqui você pode depois integrar com pontuação
}

// ================= RANKING =================
void Terminal::telaRanking() {
    cout << "\n=== RANKING ===\n";
    Fachada::getInstance()->mostrarDesempenho();
}