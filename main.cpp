#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

struct Product
{
    int id;
    int quantity;
};

void add_inventory(Product *ptr_prod) {
    ptr_prod->quantity = ptr_prod->quantity + 500;
}


int main()
{
    
    Product chip = {1, 1000};

    
    add_inventory(&chip);
    std::cout << "TITAN WAREHOUSE - ACESSO VIA STRUCT" << std::endl;
    std::cout << "ID: " << chip.id << " | Nova Quantidade: " << chip.quantity << std::endl;

    return 0;
}