#include "investment.h"
#include <cmath>
#include <iostream>
#include <iomanip>

// Constructor
Investment::Investment(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, double t_numberOfYears) {
    this->m_initialInvestment = t_initialInvestment;
    this->m_monthlyDeposit = t_monthlyDeposit;
    this->m_annualInterest = t_annualInterest;
    this->m_numberOfYears = t_numberOfYears;
    this->m_annualInterestConverted = this->convertAnnualInterest(this->m_annualInterest);
    this->m_rows = static_cast<int>(this->m_numberOfYears * 12);
    this->m_resultsWithMonthlyPayments = std::vector<std::vector<double> >(m_rows, std::vector<double>(COLS));
    this->m_resultsWithoutMonthlyPayments = std::vector<std::vector<double> >(m_rows, std::vector<double>(COLS));
    setInvestmentCalculationsMonthly();
    setInvestmentCalculationsWithoutMonthlyDeposits();
}

// Getters
double Investment::getInitialInvestment() const { return m_initialInvestment; }
double Investment::getMonthlyDeposit() const { return m_monthlyDeposit; }
double Investment::getAnnualInterest() const { return m_annualInterest; }
double Investment::getNumberOfYears() const { return m_numberOfYears; }

// Private methods
double Investment::convertAnnualInterest(double &t_num) {
    return (t_num / 100) / 12;
}

int Investment::numberOfMonthsConversion(double t_num) {
    return static_cast<int>(t_num) * 12;
}

void Investment::setInvestmentCalculationsMonthly() {
    double openingBalance = m_initialInvestment;
    double closingBalance = 0.0;
    double interest = 0.0;

    for (int i = 0; i < m_rows; ++i) {
        interest = (openingBalance + m_monthlyDeposit) * m_annualInterestConverted;
        closingBalance = openingBalance + m_monthlyDeposit + interest;
        m_resultsWithMonthlyPayments[i][0] = openingBalance;
        m_resultsWithMonthlyPayments[i][1] = m_monthlyDeposit;
        m_resultsWithMonthlyPayments[i][2] = interest;
        m_resultsWithMonthlyPayments[i][3] = closingBalance;
        openingBalance = closingBalance;
    }
}

void Investment::setInvestmentCalculationsWithoutMonthlyDeposits() {
    double openingBalance = m_initialInvestment;
    double closingBalance = 0.0;
    double interest = 0.0;

    for (int i = 0; i < m_rows; ++i) {
        interest = openingBalance * m_annualInterestConverted;
        closingBalance = openingBalance + interest;
        m_resultsWithoutMonthlyPayments[i][0] = openingBalance;
        m_resultsWithoutMonthlyPayments[i][1] = 0.0;
        m_resultsWithoutMonthlyPayments[i][2] = interest;
        m_resultsWithoutMonthlyPayments[i][3] = closingBalance;
        openingBalance = closingBalance;
    }
}

std::vector<std::vector<double> > Investment::getResultsWithMonthlyPayments() const {
    return m_resultsWithMonthlyPayments;
}

std::vector<std::vector<double> > Investment::getResultsWithoutMonthlyPayments() const {
    return m_resultsWithoutMonthlyPayments;
}
