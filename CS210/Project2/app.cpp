#include "app.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "utils.h"
#include <array>
#include <limits>

// Constructor for the App class, initializes the m_running member to true
App::App() : m_running(true) {}

// Function to display results with monthly deposits
void App::displayResultsWithMonthlyDeposits(const std::vector<std::vector<double> >& resultsWithMonthlyPayments) {
    std::cout << std::fixed << std::setprecision(2);  // Set precision to 2 decimal places
    std::cout << "Results with Monthly Deposits:\n";
    std::cout << std::setw(8) << "Year" << std::setw(20) << "Opening Amount" << std::setw(20) << "Deposited Amount"
              << std::setw(20) << "Total" << std::setw(20) << "Interest" << std::setw(20) << "Closing Balance\n";

    // Loop through the results for each month
    for (size_t month = 0; month < resultsWithMonthlyPayments.size(); ++month) {
        if ((month + 1) % 12 == 0) {  // Only display data every 12 months
            int year = (month + 1) / 12;  // Calculate the year
            std::cout << std::setw(8) << year
                      << std::setw(20) << resultsWithMonthlyPayments[month][0]
                      << std::setw(20) << resultsWithMonthlyPayments[month][1]
                      << std::setw(20) << (resultsWithMonthlyPayments[month][0] + resultsWithMonthlyPayments[month][1])
                      << std::setw(20) << resultsWithMonthlyPayments[month][3]
                      << std::setw(20) << resultsWithMonthlyPayments[month][4] << "\n";
        }
    }
    std::cout << "\n\n";
}

// Function to display results without monthly deposits
// Function to display results without monthly deposits
void App::displayResultsWithoutMonthlyDeposits(const std::vector<std::vector<double> >& resultsWithoutMonthlyPayments) {
    std::cout << std::fixed << std::setprecision(2);  // Set precision to 2 decimal places
    std::cout << "Results without Monthly Deposits:\n";
    std::cout << std::setw(8) << "Year" << std::setw(20) << "Opening Amount" << std::setw(20) << "Deposited Amount"
              << std::setw(20) << "Total" << std::setw(20) << "Interest" << std::setw(20) << "Closing Balance\n";

    // Loop through the results for each month
    for (size_t month = 0; month < resultsWithoutMonthlyPayments.size(); ++month) {
        if ((month + 1) % 12 == 0) {  // Only display data every 12 months
            int year = (month + 1) / 12;  // Calculate the year
            std::cout << std::setw(8) << year
                      << std::setw(20) << resultsWithoutMonthlyPayments[month][0]
                      << std::setw(20) << resultsWithoutMonthlyPayments[month][1]
                      << std::setw(20) << (resultsWithoutMonthlyPayments[month][0] + resultsWithoutMonthlyPayments[month][1])
                      << std::setw(20) << resultsWithoutMonthlyPayments[month][3]
                      << std::setw(20) << resultsWithoutMonthlyPayments[month][4] << "\n";
        }
    }
    std::cout << "\n\n";
}

// Function to print the main menu
void App::PrintMenu() {
    std::cout << std::setfill('*') << std::setw(52) << "*" << std::endl;  // Print a line of asterisks
    std::cout << std::setfill('*') << std::setw(20) << "*" << " Data Input " << std::setw(20) << "*" << std::endl;
    std::cout << "Inital Investment Amount: " << std::endl;
    std::cout << "Monthly Deposit: " << std::endl;
    std::cout << "Annual Interest: " << std::endl;
    std::cout << "Number of years: " << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.get();  // Wait for user input to continue
}

// Function to get user input for the investment data
std::array<double, 4> App::GetInput() {
    std::string input;
    double initialInvestment = 0.0;
    double monthlyDeposit;
    double annualInterest;
    double numYears;
    std::array<double, 4> answers;  // Array to store the inputs

    // Loop to get valid initial investment
    do {
        std::cout << "Enter the initial investment amount: ";
        std::cin >> input;

        if (!isValidDouble(input)) {  // Validate input
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();  // Clear the input stream
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            initialInvestment = std::stod(input);  // Convert input to double
            if (initialInvestment < 0) {
                std::cout << "Initial investment must be greater than 0." << std::endl;
            }
            answers[0] = initialInvestment;  // Store the valid input
            std::cin.clear();
            break;
        }

    } while (initialInvestment < 0);

    // Loop to get valid monthly deposit
    do {
        std::cout << "Enter the monthly deposit amount: ";
        std::cin >> input;

        if (!isValidInt(input)) {  // Validate input
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();  // Clear the input stream
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            monthlyDeposit = std::stoi(input);  // Convert input to integer
            if (monthlyDeposit < 0) {
                std::cout << "Monthly deposit must be greater than 0." << std::endl;
            } else {
                answers[1] = monthlyDeposit;  // Store the valid input
                std::cin.clear();
                break;
            }
        }
    } while (true);

    // Loop to get valid annual interest rate
    do {
        std::cout << "Enter the annual interest rate: ";
        std::cin >> input;

        if (!isValidDouble(input)) {  // Validate input
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();  // Clear the input stream
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            annualInterest = std::stod(input);  // Convert input to double
            if (annualInterest < 0) {
                std::cout << "Annual interest must be greater than 0." << std::endl;
            } else {
                answers[2] = annualInterest;  // Store the valid input
                std::cin.clear();
                break;
            }
        }
    } while (true);

    // Loop to get valid number of years
    do {
        std::cout << "Enter the number of years for this investment: ";
        std::cin >> input;

        if (!isValidInt(input)) {  // Validate input
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();  // Clear the input stream
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            numYears = std::stoi(input);  // Convert input to integer
            if (numYears < 0) {
                std::cout << "Number of years must be greater than 0." << std::endl;
            } else {
                answers[3] = numYears;  // Store the valid input
                std::cin.clear();
                break;
            }
        }
    } while (true);

    std::cout << std::endl;
    answers[0] = initialInvestment;
    answers[1] = monthlyDeposit;
    answers[2] = annualInterest;
    answers[3] = numYears;
    return answers;
}

// Function to display confirmation of user choices
void App::PrintConfirmChoices() {
    std::cout << std::setfill('-') << std::setw(52) << "-" << std::endl;  // Print separator line
    std::cout << "Press 'i' to change the initial investment amount." << std::endl;
    std::cout << "Press 'm' to change the monthly deposit amount." << std::endl;
    std::cout << "Press 'a' to change the annual interest rate." << std::endl;
    std::cout << "Press 'y' to change the number of years." << std::endl;
    std::cout << "Press 'c' to continue." << std::endl;
    std::cout << "Press 'q' to quit." << std::endl;
}

// Function to confirm or change inputted results
void App::ConfirmResults(std::array<double, 4>& results) {
    bool choicesConfirmed = false;
    std::string input;
    char choice;

    while (!choicesConfirmed && this->m_running) {
        // Print the confirmation menu
        std::cout << std::setfill('*') << std::setw(19) << "*" << " Confirmation " << std::setw(19) << "*" << std::endl;
        std::cout << "Initial Investment Amount: $" << results[0] << std::endl;
        std::cout << "Monthly Deposit: $" << results[1] << std::endl;
        std::cout << "Annual Interest: " << results[2] << "%" << std::endl;
        std::cout << "Number of years: " << results[3] << std::endl;

        this->PrintConfirmChoices();  // Display options for the user
        std::cin >> choice;  // Get the user's choice

        // Clear the input stream to avoid leftover characters
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Handle the user's choice and allow changes to the inputs
        switch (choice) {
            case 'i':
                do {
                    std::cout << "Enter the new initial investment amount: ";
                    std::cin >> input;
                    std::cout << std::endl;
                    if (!isValidDouble(input)) {
                        std::cout << "Invalid input. Please enter a valid number." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } else {
                        results[0] = std::stod(input);  // Update the initial investment
                        std::cout << std::endl;
                        break;
                    }
                } while (true);
                break;
            case 'm':
                do {
                    std::cout << "Enter the new monthly deposit amount: ";
                    std::cin >> input;
                    std::cout << std::endl;
                    if (!isValidDouble(input)) {
                        std::cout << "Invalid input. Please enter a valid number." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } else {
                        results[1] = std::stod(input);  // Update the monthly deposit
                        std::cout << std::endl;
                        break;
                    }
                } while (true);
                break;
            case 'a':
                do {
                    std::cout << "Enter the new annual interest rate: ";
                    std::cin >> input;
                    std::cout << std::endl;
                    if (!isValidDouble(input)) {
                        std::cout << "Invalid input. Please enter a valid number." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } else {
                        results[2] = std::stod(input);  // Update the annual interest rate
                        std::cout << std::endl;
                        break;
                    }
                } while (true);
                break;
            case 'y':
                do {
                    std::cout << "Enter the new number of years for this investment: ";
                    std::cin >> input;
                    std::cout << std::endl;
                    if (!isValidInt(input)) {
                        std::cout << "Invalid input. Please enter a valid number." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } else {
                        results[3] = std::stoi(input);  // Update the number of years
                        std::cout << std::endl;
                        break;
                    }
                } while (true);
                break;
            case 'c':  // Confirm the input
            case 'C':
                choicesConfirmed = true;
                break;
            case 'q':  // Quit the application
            case 'Q':
                this->Quit();
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
}

// Function to check if the application is running
bool App::isRunning() const {
    return m_running;
}

// Function to quit the application
void App::Quit() {
    std::cout << "Goodbye!" << std::endl;
    this->m_running = false;  // Set the running state to false
}
