#include "investment.h"
#include <cmath>
#include <iostream>
#include <iomanip>

// Constructor for the Investment class
Investment::Investment(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, double t_numberOfYears) {
    // Initialize member variables with input parameters
    this->m_initialInvestment = t_initialInvestment;
    this->m_monthlyDeposit = t_monthlyDeposit;
    this->m_annualInterest = t_annualInterest;
    this->m_numberOfYears = t_numberOfYears;

    // Convert the annual interest rate to a monthly interest rate
    this->m_annualInterestConverted = this->convertAnnualInterest(this->m_annualInterest);

    // Calculate the total number of months based on the number of years
    this->m_rows = static_cast<int>(this->m_numberOfYears * 12);

    // Initialize the 2D vector for results with monthly payments (each row corresponds to a month, and there are 4 columns)
    this->m_resultsWithMonthlyPayments = std::vector<std::vector<double> >(m_rows, std::vector<double>(COLS));

    // Initialize the 2D vector for results without monthly payments
    this->m_resultsWithoutMonthlyPayments = std::vector<std::vector<double> >(m_rows, std::vector<double>(COLS));

    // Calculate the investment results with monthly deposits
    setInvestmentCalculationsMonthly();

    // Calculate the investment results without monthly deposits
    setInvestmentCalculationsWithoutMonthlyDeposits();
}

// Getter methods to access private members
double Investment::getInitialInvestment() const { return m_initialInvestment; }
double Investment::getMonthlyDeposit() const { return m_monthlyDeposit; }
double Investment::getAnnualInterest() const { return m_annualInterest; }
double Investment::getNumberOfYears() const { return m_numberOfYears; }

// Private method to convert annual interest rate to monthly interest rate
// Takes the annual interest rate (as a reference) and returns monthly interest rate
double Investment::convertAnnualInterest(double &t_num) {
    return (t_num / 100) / 12;  // Convert percentage to decimal and divide by 12 for monthly rate
}

// Helper method to convert the number of years to the number of months (for easier calculations)
int Investment::numberOfMonthsConversion(double t_num) {
    return static_cast<int>(t_num) * 12;  // Multiply the number of years by 12 to get the total number of months
}

// Method to calculate the investment results with monthly deposits
void Investment::setInvestmentCalculationsMonthly() {
    double openingBalance = m_initialInvestment;
    double closingBalance = 0.0;
    double interest = 0.0;

    for (int i = 0; i < m_rows; ++i) {
        interest = (openingBalance + m_monthlyDeposit) * m_annualInterestConverted;
        closingBalance = openingBalance + m_monthlyDeposit + interest;

        m_resultsWithMonthlyPayments[i][0] = openingBalance;
        m_resultsWithMonthlyPayments[i][1] = m_monthlyDeposit;
        m_resultsWithMonthlyPayments[i][2] = openingBalance + m_monthlyDeposit; // Total
        m_resultsWithMonthlyPayments[i][3] = interest;
        m_resultsWithMonthlyPayments[i][4] = closingBalance;

        openingBalance = closingBalance;
    }
}

// Method to calculate the investment results without monthly deposits
void Investment::setInvestmentCalculationsWithoutMonthlyDeposits() {
    double openingBalance = m_initialInvestment;
    double closingBalance = 0.0;
    double interest = 0.0;

    for (int i = 0; i < m_rows; ++i) {
        interest = openingBalance * m_annualInterestConverted;
        closingBalance = openingBalance + interest;

        m_resultsWithoutMonthlyPayments[i][0] = openingBalance;
        m_resultsWithoutMonthlyPayments[i][1] = 0.0;
        m_resultsWithoutMonthlyPayments[i][2] = openingBalance; // Total
        m_resultsWithoutMonthlyPayments[i][3] = interest;
        m_resultsWithoutMonthlyPayments[i][4] = closingBalance;

        openingBalance = closingBalance;
    }
}

// Getter method to retrieve the vector of results with monthly payments
std::vector<std::vector<double> > Investment::getResultsWithMonthlyPayments() const {
    return m_resultsWithMonthlyPayments;
}

// Getter method to retrieve the vector of results without monthly payments
std::vector<std::vector<double> > Investment::getResultsWithoutMonthlyPayments() const {
    return m_resultsWithoutMonthlyPayments;
}
