#include <iostream>
#include "item.hpp"

int main() {
    // Blank Item
    Item item1();
    std::cout << "Made a blank item" << std::endl;

    // No discount Item
    Item sedan("Sedan", 30000, "A sedan");
    std::cout << "Sedan name: " << sedan.getName() << std::endl;
    std::cout << "Sedan price: " << sedan.getPrice() << std::endl;
    std::cout << "Sedan desc: " << sedan.getDescription() << std::endl;
    
    // Item(string name, float price, string description, float discount)
    Item apple("Apple", 6, "An apple", 0.75);
    std::cout << "Made an apple that costs " << apple.getPrice() << std::endl;

    // First discount check
    std::cout << "\nFirst discount check" << std::endl;
    std::cout << apple.hasDiscount() << std::endl;

    // Making the item free
    std::cout << "\nApplying 100% off discount to the apple" << std::endl;
    apple.setDiscount(0);
    std::cout << apple.hasDiscount() << std::endl;
    std::cout << "Apple price is now " << apple.getPrice() << std::endl;

    // Restoring its original value
    std::cout << "\nRestoring the apple's original price" << std::endl;
    apple.removeDiscount();
    std::cout << "The apple's original price is " << apple.getPrice() << std::endl;

    // Applying discount to sedan
    std::cout << "\nApplying 37.5% off discount to the sedan" << std::endl;
    sedan.setDiscount(0.625);
    std::cout << sedan.hasDiscount() << std::endl;
    std::cout << "Sedan price is now " << sedan.getPrice() << std::endl;

    // Restoring its original value
    std::cout << "\nRestoring the sedan's original price" << std::endl;
    sedan.removeDiscount();
    std::cout << "The sedan's original price is " << sedan.getPrice() << std::endl;

    return 0;
}