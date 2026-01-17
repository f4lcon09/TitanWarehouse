#include <iostream>

struct Product
{
    int id;
    int qty;
};

// Function to manage stock.
// Receives a pointer (memory address) to modify the original product directly.
void stock_manager(Product *ptr_prod, int amount)
{
    ptr_prod->qty = ptr_prod->qty + amount;
}

int main()
{
    // Initialize the single product in the system
    Product chip = {1, 1000};
    
    bool running = true;

    // Main System Loop
    while (running)
    {
        std::cout << "Select Action:\n[1] Check Status\n[2] Update Stock\n[3] Exit\n>> ";
        
        int choice;
        std::cin >> choice;
        
        std::cout << "\n------------------------------\n";

        switch (choice)
        {
        case 1:
            // Display current product details
            std::cout << "Product: Neural Chip (ID " << chip.id << ") | Qty: " << chip.qty << std::endl;
            break;

        case 2:
        { 
            // Scoped block for local variables
            int edit_qty;

            std::cout << "Enter quantity to change (use negative to remove): ";
            std::cin >> edit_qty;

            // Call function passing the address (&) of the chip
            stock_manager(&chip, edit_qty);

            std::cout << "Stock updated successfully!" << std::endl;
            break; 
        }

        case 3:
            // Exit the loop
            running = false;
            std::cout << "System shutting down..." << std::endl;
            break;

        default:
            std::cout << "Invalid Option!" << std::endl;
            break;
        }
        
        std::cout << "\n------------------------------\n";
    }

    return 0;
}