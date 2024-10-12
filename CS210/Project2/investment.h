#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <vector>

// Investment class declaration
class Investment {
    public:
        // Constructor that initializes the investment details
        Investment(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, double t_numberOfYears);

        // Getter functions to retrieve private member variables
        double getInitialInvestment() const;  // Get the initial investment amount
        double getMonthlyDeposit() const;     // Get the monthly deposit amount
        double getAnnualInterest() const;     // Get the annual interest rate
        double getNumberOfYears() const;      // Get the number of years for the investment

        // Functions to retrieve the calculated results for investments with and without monthly payments
        std::vector<std::vector<double> > getResultsWithMonthlyPayments() const;  // Get results with monthly deposits
        std::vector<std::vector<double> > getResultsWithoutMonthlyPayments() const;  // Get results without monthly deposits

    private:
        // Private member variables to store investment details
        double m_initialInvestment;  // Initial investment amount
        double m_monthlyDeposit;     // Monthly deposit amount
        double m_annualInterest;     // Annual interest rate
        double m_numberOfYears;      // Number of years for the investment
        double m_annualInterestConverted;  // Monthly interest rate converted from annual interest rate
        int m_rows;  // Number of months (years * 12)

        // 2D vectors to store calculated results with and without monthly payments
        std::vector<std::vector<double> > m_resultsWithMonthlyPayments;
        std::vector<std::vector<double> > m_resultsWithoutMonthlyPayments;

        // Constant to define the number of columns in the result vectors (e.g., opening balance, deposit, interest, closing balance)
        static const int COLS = 5;

        // Private methods
        double convertAnnualInterest(double &t_num);  // Convert annual interest rate to a monthly interest rate
        int numberOfMonthsConversion(double t_num);   // Convert the number of years into months
        int getNumberOfMonthlyDeposits();             // Calculate the total number of monthly deposits
        void setInvestmentCalculationsMonthly();      // Calculate results for investment with monthly deposits
        void setInvestmentCalculationsWithoutMonthlyDeposits();  // Calculate results for investment without monthly deposits
};

#endif // INVESTMENT_H
