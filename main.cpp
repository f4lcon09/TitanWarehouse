#include <iostream>
using namespace std;

int main() {
    int pecas = 500;
    
    // O PONTEIRO: Uma variável que guarda um endereço (o asterisco * diz isso)
    int* endereco_das_pecas = &pecas;

    cout << "TITAN WAREHOUSE - ACESSO DIRETO" << endl;
    cout << "Valor original: " << pecas << endl;

    // A MÁGICA: Vamos mudar o valor usando o ponteiro (Desreferenciação)
    *endereco_das_pecas = 999; 

    cout << "Novo valor (mudado pelo endereco): " << pecas << endl;
    cout << "Onde isso aconteceu? No endereco: " << endereco_das_pecas << endl;

    return 0;
}