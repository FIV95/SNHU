#include "app.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Validations.h"

// print methods

// constructor
App::App()
{
    this->running = true;
    this->hasDocument = false;
    this->osType = Validations::osCheck();
}

void printMenu()
{
    std::cout << std::setfill('=') << std::setw(45) << "=" << std::endl;
    std::cout << "MENU" << std::endl;
    std::cout << std::setfill('=') << std::setw(45) << "=" << std::endl;

    std::cout << "Please select an option by typing the corresponding number:" << std::endl;

    std::cout << "1. Set input file path" << std::endl;
    std::cout << "   - Allow the user to specify the file path for the input file." << std::endl;

    std::cout << "2. Search for an item" << std::endl;
    std::cout << "   - Prompt a user to input the item, or word, they wish to look for." << std::endl;
    std::cout << "   - Return a numeric value for the frequency of the specific word." << std::endl;

    std::cout << "3. Print frequency of all items" << std::endl;
    std::cout << "   - Print the list with numbers that represent the frequency of all items purchased." << std::endl;

    std::cout << "4. Print histogram of item frequencies" << std::endl;
    std::cout << "   - Print the same frequency information for all the items in the form of a histogram." << std::endl;

    std::cout << "5. Exit the program" << std::endl;

    std::cout << std::setfill('=') << std::setw(45) << "=" << std::endl;
}

// Procedurial methods

void getInput()
{
    char input;
    do
    {
        std::cout "Please enter a valid option: ";
        std::cin >> input;
    } while (!Validations::isValidChar(input) && !(Validations::IsInMenuRange(input)););
}
