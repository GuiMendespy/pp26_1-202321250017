#pragma once
#include <vector>
#include <string>
using namespace std;

class Logger {
    private:
        vector<string> logs;
    public:
        Logger();
        void registrar(string acao);
        void gerarRelatorio();
};