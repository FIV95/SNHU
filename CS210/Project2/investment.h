#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <vector>

class Investment {
    public:
        Investment(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, double t_numberOfYears);
        double getInitialInvestment() const;
        double getMonthlyDeposit() const;
        double getAnnualInterest() const;
        double getNumberOfYears() const;
        std::vector<std::vector<double> > getResultsWithMonthlyPayments() const;
        std::vector<std::vector<double> > getResultsWithoutMonthlyPayments() const;

    private:
        double m_initialInvestment;
        double m_monthlyDeposit;
        double m_annualInterest;
        double m_numberOfYears;
        double m_annualInterestConverted;
        int m_rows;
        std::vector<std::vector<double> > m_resultsWithMonthlyPayments;
        std::vector<std::vector<double> > m_resultsWithoutMonthlyPayments;
        static const int COLS = 5;

        double convertAnnualInterest(double &t_num);
        int numberOfMonthsConversion(double t_num);
        int getNumberOfMonthlyDeposits();
        void setInvestmentCalculationsMonthly();
        void setInvestmentCalculationsWithoutMonthlyDeposits();
};

#endif // INVESTMENT_H
