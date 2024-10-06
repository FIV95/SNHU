#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <vector>
#include <string>

class Investment {
public:
    // Constructor
    Investment(double num1, double num2, double num3, double num4);

    // Getters
    double getInitialInvestment() const;
    double getMonthlyDeposit() const;
    double getAnnualInterest() const;
    double getNumberOfYears() const;


    // Display monthly results
    void displayMonthlyResultsWithDeposits();
    void displayMonthlyResultsWithoutDeposits();

private:
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    double numberOfYears;
    double annualInterestInPercent;
    double annualInterestConverted;
    int rows;
    static const int cols = 5;
    std::vector<std::vector<double>> resultsWithMonthlyPayments;
    std::vector<std::vector<double>> resultsWithoutMonthlyPayments;

    double convertAnnualInterest(double &num);
    bool decimalCheckYears(double num);
    int numberOfMonthsConversion(double num);
    int getNumberOfMonthlyDeposits();
    void investmentCalculationsMonthly(std::vector<std::vector<double>>& results);
    void investmentCalculationsWithoutMonthlyDeposits(std::vector<std::vector<double>>& results);
};

#endif // INVESTMENT_H