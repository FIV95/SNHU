#include "app.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "validation.h"

// Constructor
App::App() {
    this->_running = true;
    this->_hasDocument = false;
    this->_queryComplete = false;
    this->setOsType(Validation::osCheck());
}

void App::printMenu() {
    std::cout << std::setfill('=') << std::setw(45) << "=" << std::endl;
    std::cout << "MENU";
    std::cout << (this->hasDocument() ? "-- Document Loaded: '" + this->getCurrentDocument()->getTitle() + "'" : "") << std::endl;
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

// Define setInput method
void App::setInput(const char &input) {
    this->_input = input;
}

// define promptForQuery method
void App::promptForQuery() {
    std::string query;
    std::cout << "Please enter the query: ";
    std::cin >> query;
    setQuery(query);
}

// Define the method to prompt for input from the user
void App::promptForInput() {
    char input;
    do {
        std::cout << "Please enter a valid option: ";
        std::cin >> input;
    } while (!Validation::isValidChar(std::string(1, input)) || !Validation::intIsInMenuRange(std::string(1, input)));
    setInput(input); // Set the input after validation
}

void App::setCurrentDocument(InputDocument* inputDocument) {
    this->_currentDocument = inputDocument;
}

void App::setHasDocument(bool hasDocument) {
    this->_hasDocument = hasDocument;
}

void App::setRunning(bool running) {
    this->_running = running;
}

void App::setQuery(const std::string &query) {
    this->_query = query;
}

void App::setQueryComplete(bool queryComplete) {
    this->_queryComplete = queryComplete;
}

void App::promptForQueryComplete() {
    char input;
    do {
        std::cout << "Want to search for something else? (Y/N): ";
        std::cin >> input;
    } while (!Validation::isValidChar(std::string(1, input)));
    setQueryComplete(input == 'N' || input == 'n');
}

void App::setOption1Results(int result) {
    this->_option1Results = result;
}

void App::printOption1Results(std::string query) {
    std::cout << "The query " << query << " appears " << this->getOption1Results() << " times." << std::endl;
}

void App::printOption2Results(std::vector<Product> products) {
    std::cout << "Option 2 results: " << std::endl;
    for (const auto &product : products) {
        std::cout << "Product: " << product.getName() << "|| Quantity: " << product.getQty() << std::endl;
    }
}
