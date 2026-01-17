#include <iostream>

struct Tanque
{
    int litro;
    int capacidade_maxima;
};

void abastecer(Tanque *ptr_abs)
{
    // a seta ta falando, vai la na struct e busca o litro e o capacidade maxima
    // o *ptr_abs é o controle remoto, ele controla todo mundo desde que especifique o que ele controla
    if (ptr_abs->litro + 20 > ptr_abs->capacidade_maxima)
    {
       ptr_abs->litro = ptr_abs->capacidade_maxima;
    }
    else 
    {
        ptr_abs->litro = ptr_abs->litro + 20;
    }
}

int main()
{
    Tanque meu_tanque;
    meu_tanque.capacidade_maxima = 100;
    meu_tanque.litro = 90;

    abastecer(&meu_tanque);
    std::cout << "Litros: " << meu_tanque.litro << std::endl;
}