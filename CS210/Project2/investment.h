#ifndef INVESTMENT_H
#define INVESTMENT_H
#include <cmath>

class Investment {
  public:
  Investment(double num1, double num2, double num3 , double num4) {
    this->initialInvestment = num1;
    this->monthlyDeposit = num2;
    this->annualInterest = num3;
    this->numberOfYears = num4;
  }
  
  // Getters
  double getInitialInvestment() const {return initialInvestment;}
  double getMonthlyDeposit() const {return monthlyDeposit;}
  double getAnnualInterest() const {return annualInterest;}
  double getNumberOfYears() const {return numberOfYears;}

  // Setters

  void setInitialInvestment(double num) { initialInvestment = num;}
  void getMonthlyDeposit(double num) {monthlyDeposit = num;}
  void setAnnualInterest(double num) {annualInterest = num;}
  void setNumberOfYears(double num) {numberOfYears = num;}

  private:
  double initialInvestment;
  double monthlyDeposit;
  double annualInterest;
  double numberOfYears;
  // matrix to hold our data
  // two rows - 1 for:
  //              *Financial outcomes with monthly payments
  //              *Financial outcomes without monthly payments
  //
  // Year end balances // Year-earned Interest
  // Year end balances // Year-earned interest - based on monthly deposit value
  
  

  void convertAnnualInterest(double& num)
  {
    num = num / 100;
  }

  bool decimalCheckYears(double num)
  {
    return num == static_cast<int>(num);
  }

  int numberOfMonthsConversion(double num)
  {
    int numberOfMonths;
    if (this->decimalCheckYears(this->getNumberOfYears()))
    {
      numberOfMonths = 12 * this->getNumberOfYears();
      return numberOfMonths;
    }
    else
    {
      int remainder;
      int years = std::floor(this->getNumberOfYears());
      int months;
      remainder = this->getNumberOfYears() - years;
      months = remainder * 12;
      numberOfMonths = (12 * years) + std::floor(months);
      return numberOfMonths;

    }
  }

  int GetNumberOfMonthlyDeposits()
  {
    return this->numberOfMonthsConversion(this->numberOfYears) * this->getMonthlyDeposit();
  }


}

#endif // INVESTMENT_H

