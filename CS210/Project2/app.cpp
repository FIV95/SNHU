#include "app.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "utils.h"
#include <array>
#include <limits>

App::App() : m_running(true)
{
}

void App::displayResultsWithMonthlyDeposits(const std::vector<std::vector<double> >& resultsWithMonthlyPayments) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Results with Monthly Deposits:\n";
    std::cout << "\tYear\tOpening Amount\t\tDeposited Amount\tTotal\t\tInterest\t\tClosing Balance\n";

    for (size_t month = 0; month < resultsWithMonthlyPayments.size(); ++month) {
        if ((month + 1) % 12 == 0) {
            int year = (month + 1) / 12;
            std::cout <<"\t" << year << "\t";

        std::cout << "$" << resultsWithMonthlyPayments[month][0] << "\t\t\t"
                  << "$" << resultsWithMonthlyPayments[month][1] << "\t\t\t"
                  << "$" << resultsWithMonthlyPayments[month][2] << "\t\t"
                  << "$" << resultsWithMonthlyPayments[month][3] << "\t\t\t"
                  << "$" << resultsWithMonthlyPayments[month][4] << "\n";
        }
    }
    std::cout << "\n\n";
}

void App::displayResultsWithoutMonthlyDeposits(const std::vector<std::vector<double> >& resultsWithoutMonthlyPayments) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Results without Monthly Deposits:\n";
    std::cout << "\tYear\tOpening Amount\t\tDeposited Amount\tTotal\t\tInterest\t\tClosing Balance\n";

    for (size_t month = 0; month < resultsWithoutMonthlyPayments.size(); ++month) {
        if ((month + 1) % 12 == 0) {
            int year = (month + 1) / 12;
            std::cout <<"\t" << year << "\t";

        std::cout << "$" << resultsWithoutMonthlyPayments[month][0] << "\t\t\t"
                  << "$" << resultsWithoutMonthlyPayments[month][1] << "\t\t\t"
                  << "$" << resultsWithoutMonthlyPayments[month][2] << "\t\t"
                  << "$" << resultsWithoutMonthlyPayments[month][3] << "\t\t\t"
                  << "$" << resultsWithoutMonthlyPayments[month][4] << "\n";
        }
    }
    std::cout << "\n\n";
}

void App::PrintMenu()
{
    // Print the top border
    std::cout << std::setfill('*') << std::setw(52) << "*" << std::endl;

    // Print the title with padding
    std::cout << std::setfill('*') << std::setw(20) << "*" << " Data Input " << std::setw(20) << "*" << std::endl;

    std::cout << "Inital Investment Amount: " << std::endl;

    std::cout << "Monthly Deposit: " << std::endl;

    std::cout << "Annual Interest: " << std::endl;

    std::cout << "Number of years: " << std::endl;

    std::cout << "Press any key to continue..." << std::endl;
    std::cin.get();
}

std::array<double, 4> App::GetInput()
{
    std::string input;
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    double numYears;
    std::array<double, 4> answers;

    do
    {
        std::cout << "Enter the initial investment amount: ";
        std::cin >> input;

        if (!isValidDouble(input))
        {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            initialInvestment = std::stod(input);
            if (initialInvestment < 0)
            {
                std::cout << "Initial investment must be greater than 0." << std::endl;
            }
            answers[0] = initialInvestment;
            std::cin.clear();
            break;
        }

    } while (initialInvestment < 0);

    do
    {
        std::cout << "Enter the monthly deposit amount: ";
        std::cin >> input;

        if (!isValidInt(input))
        {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();                                                   // Clear the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        }
        else
        {
            monthlyDeposit = std::stoi(input);
            if (monthlyDeposit < 0)
            {
                std::cout << "Monthly deposit must be greater than 0." << std::endl;
            }
            else
            {
                answers[1] = monthlyDeposit;
                std::cin.clear();
                break;
            }
        }
    } while (true);

    do
    {
        std::cout << "Enter the annual interest rate: ";
        std::cin >> input;

        if (!isValidDouble(input))
        {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            annualInterest = std::stod(input);
            if (annualInterest < 0)
            {
                std::cout << "Annual interest must be greater than 0." << std::endl;
            }
            else
            {
                answers[2] = annualInterest;
                std::cin.clear();
                break;
            }
        }
    } while (true);

    do
    {
        std::cout << "Enter the number of years for this investment: ";
        std::cin >> input;

        if (!isValidInt(input))
        {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            numYears = std::stoi(input);
            if (numYears < 0)
            {
                std::cout << "Number of years must be greater than 0." << std::endl;
            }
            else
            {
                answers[3] = numYears;
                std::cin.clear();
                break;
            }
        }
    } while (true);

    std::cout << std::endl;
    return {answers[0], answers[1], answers[2], answers[3]};
}

void ::App::PrintConfirmChoices()
{
    std::cout << std::setfill('-') << std::setw(52) << "-" << std::endl;
    std::cout << "Press 'i' to change the initial investment amount." << std::endl;
    std::cout << "Press 'm' to change the monthly deposit amount." << std::endl;
    std::cout << "Press 'a' to change the annual interest rate." << std::endl;
    std::cout << "Press 'y' to change the number of years." << std::endl;
    std::cout << "Press 'c' to continue." << std::endl;
    std::cout << "Press 'q' to quit." << std::endl;
}

void App::ConfirmResults(std::array<double, 4>& results) {
    bool choicesConfirmed = false;
    std::string input;
    char choice;

    while (!choicesConfirmed && this->m_running) {
        std::cout << std::setfill('*') << std::setw(19) << "*" << " Confirmation " << std::setw(19) << "*" << std::endl;
        std::cout << "Initial Investment Amount: $" << results[0] << std::endl;
        std::cout << "Monthly Deposit: $" << results[1] << std::endl;
        std::cout << "Annual Interest: " << results[2] << "%" << std::endl;
        std::cout << "Number of years: " << results[3] << std::endl;

        // Ask user if they want to continue with input or change it
        this->PrintConfirmChoices();
        std::cin >> choice;

        // Clear the input stream to remove any leftover characters
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
                        results[0] = std::stod(input);
                        std::cout << std::endl;
                        if (results[0] < 0) {
                            std::cout << "Initial investment must be greater than 0." << std::endl;
                        }
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
                        results[1] = std::stod(input);
                        std::cout << std::endl;
                        if (results[1] < 0) {
                            std::cout << "Monthly deposit must be greater than 0." << std::endl;
                        }
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
                        results[2] = std::stod(input);
                        std::cout << std::endl;
                        if (results[2] < 0) {
                            std::cout << "Annual interest must be greater than 0." << std::endl;
                        }
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
                        results[3] = std::stoi(input);
                        std::cout << std::endl;
                        if (results[3] < 0) {
                            std::cout << "Number of years must be greater than 0." << std::endl;
                        }
                        break;
                    }
                } while (true);
                break;
            case 'c':
            case 'C':
                choicesConfirmed = true;
                break;
            case 'q':
            case 'Q':
                this->Quit();
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
}

bool App::isRunning() const
{
    return m_running;
}

void App::Quit()
{
    std::cout << "Goodbye!" << std::endl;
    this->m_running = false;
}
