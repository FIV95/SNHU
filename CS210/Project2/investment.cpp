#include "investment.h"
#include <cmath>
#include <iostream>
#include <iomanip>

// Constructor
Investment::Investment(double num1, double num2, double num3, double num4) {
    this->initialInvestment = num1;
    this->monthlyDeposit = num2;
    this->annualInterestInPercent = num3;
    this->numberOfYears = num4;
    this->annualInterestConverted = this->convertAnnualInterest(this->annualInterestInPercent);
    this->rows = this->numberOfYears * 12;
    this->resultsWithMonthlyPayments = std::vector<std::vector<double>>(rows, std::vector<double>(cols));
    this->resultsWithoutMonthlyPayments = std::vector<std::vector<double>>(rows, std::vector<double>(cols));
    investmentCalculationsMonthly(resultsWithMonthlyPayments);
    investmentCalculationsWithoutMonthlyDeposits(resultsWithoutMonthlyPayments);
    
}

// Getters
double Investment::getInitialInvestment() const { return initialInvestment; }
double Investment::getMonthlyDeposit() const { return monthlyDeposit; }
double Investment::getAnnualInterest() const { return annualInterest; }
double Investment::getNumberOfYears() const { return numberOfYears; }

void Investment::displayMonthlyResultsWithDeposits() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\tMonth\tOpening Amount\t\tDeposited Amount\tTotal\t\tInterest\t\tClosing Balance\n";

    for (int month = 0; month < rows; ++month) {
        if ((month + 1) % 12 == 0) {
            std::cout << "\tYear " << (month + 1) / 12 << "\t";
        } else {
            std::cout <<"\t" << month + 1 << "\t";
        }
        std::cout << resultsWithMonthlyPayments[month][0] << "\t\t\t"
                  << resultsWithMonthlyPayments[month][1] << "\t\t\t"
                  << resultsWithMonthlyPayments[month][2] << "\t\t"
                  << resultsWithMonthlyPayments[month][3] << "\t\t\t"
                  << resultsWithMonthlyPayments[month][4] << "\n";
    }
}


// Private methods
double Investment::convertAnnualInterest(double &num) {
    return num / 100;
}

bool Investment::decimalCheckYears(double num) {
    return num == static_cast<int>(num);
}

int Investment::numberOfMonthsConversion(double num) {
    return static_cast<int>(num) * 12;
}

int Investment::getNumberOfMonthlyDeposits() {
    return this->numberOfMonthsConversion(this->numberOfYears) * this->getMonthlyDeposit();
}

void Investment::investmentCalculationsMonthly(std::vector<std::vector<double>>& results) {
    double balanceWithDeposits = initialInvestment;
    double monthlyInterestRate = annualInterestConverted / 12;

    for (int month = 0; month < rows; ++month) {
        double openingAmount = balanceWithDeposits;
        double depositedAmount = monthlyDeposit;
        double total = openingAmount + depositedAmount;
        double interest = total * monthlyInterestRate;
        double closingBalance = total + interest;

        resultsWithMonthlyPayments[month][0] = openingAmount;
        resultsWithMonthlyPayments[month][1] = depositedAmount;
        resultsWithMonthlyPayments[month][2] = total;
        resultsWithMonthlyPayments[month][3] = interest;
        resultsWithMonthlyPayments[month][4] = closingBalance;

        balanceWithDeposits = closingBalance;
    }
}

void Investment::investmentCalculationsWithoutMonthlyDeposits(std::vector<std::vector<double>>& results) {
    double balanceWithoutDeposits = initialInvestment;
    double monthlyInterestRate = annualInterestConverted / 12;

    for (int month = 0; month < rows; ++month) {
        double openingAmount;
        double interest = balanceWithoutDeposits * monthlyInterestRate;
        if (month == 0) {
            openingAmount = initialInvestment;
        } else {
            openingAmount = resultsWithoutMonthlyPayments[month - 1][2];
        }
        double total = openingAmount + interest;

        resultsWithoutMonthlyPayments[month][0] = openingAmount;
        resultsWithoutMonthlyPayments[month][1] = 0.0;
        resultsWithoutMonthlyPayments[month][2] = total;
        resultsWithoutMonthlyPayments[month][3] = interest;
        resultsWithoutMonthlyPayments[month][4] = total;

        balanceWithoutDeposits = total;
    }
}