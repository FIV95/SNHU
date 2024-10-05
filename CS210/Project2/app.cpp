#include "app.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "utils.h"
#include <array>

App::App() : running(true)
{
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
}

void ::App::ConfirmResults(std::array<double, 4>& results)
{
    char choice;
    std::string input;
    bool choicesConfirmed = false;

    // Print the top border
    std::cout << std::setfill('*') << std::setw(52) << "*" << std::endl;

    // Print the title with padding
    std::cout << std::setfill('*') << std::setw(19) << "*" << " Confirmation " << std::setw(19) << "*" << std::endl;

    std::cout << "Initial Investment Amount: $" << results[0] << std::endl;
    std::cout << "Monthly Deposit: $" << results[1] << std::endl;
    std::cout << "Annual Interest: " << results[2] << "%" << std::endl;
    std::cout << "Number of years: " << results[3] << std::endl;

    //  ask user if they want to continue with input or change it
    this->PrintConfirmChoices();
    while (!choicesConfirmed) {
        std::cin >> choice;
    switch (choice)
    {
    case 'i':
        do
        {
            std::cout << "Enter the new initial investment amount: ";
            std::cin >> input;
            std::cout << std::endl;

            if (!isValidDouble(input))
            {
                std::cout << "Invalid input. Please enter a valid number." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                results[0] = std::stod(input);
                std::cout << std::endl;
                if (results[0] < 0)
                {
                    std::cout << "Initial investment must be greater than 0." << std::endl;
                }
                std::cin.clear();
                break;
            }
        } while (true);
        this->ConfirmResults(results);
        break;
    case 'm':
        do
        {
            std::cout << "Enter the new monthly deposit amount: ";
            std::cin >> input;
            std::cout << std::endl;

            if (!isValidInt(input))
            {
                std::cout << "Invalid input. Please enter a valid number." << std::endl;
                std::cin.clear();                                                   // Clear the error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            }
            else
            {
                results[1] = std::stoi(input);
                std::cout << std::endl;
                if (results[1] < 0)
                {
                    std::cout << "Monthly deposit must be greater than 0." << std::endl;
                }
                std::cin.clear();
                break;
            }
        } while (true);
        this->ConfirmResults(results);
        break;
    case 'a':
        do
        {
            std::cout << "Enter the new annual interest rate: ";
            std::cin >> input;
            std::cout << std::endl;

            if (!isValidDouble(input))
            {
                std::cout << "Invalid input. Please enter a valid number." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                results[2] = std::stod(input);
                std::cout << std::endl;
                if (results[2] < 0)
                {
                    std::cout << "Annual interest must be greater than 0." << std::endl;
                }
                std::cin.clear();
                break;
            }
        } while (true);
        this->ConfirmResults(results);
        break;
    case 'y':
        do
        {
            std::cout << "Enter the new number of years for this investment: ";
            std::cin >> input;
            std::cout << std::endl;

            if (!isValidInt(input))
            {
                std::cout << "Invalid input. Please enter a valid number." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                results[3] = std::stoi(input);
                std::cout << std::endl;
                if (results[3] < 0)
                {
                    std::cout << "Number of years must be greater than 0." << std::endl;
                }
                std::cin.clear();
                break;
            }
        } while (true);
        this->ConfirmResults(results);
        break;
    case 'c':
        choicesConfirmed = true;
        break;

    default:
        break;

    }
    }
}
