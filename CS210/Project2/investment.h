#ifndef INVESTMENT_H
#define INVESTMENT_H
#include <cmath>
#include <vector>
#include <string>
#include <string>

class Investment {
  public:
  Investment(double num1, double num2, double num3 , double num4, const std::string& name) {
    this->initialInvestment = num1;
    this->monthlyDeposit = num2;
    this->annualInterestInPercent = num3;
    this->numberOfYears = num4;
    this->name = name;
    this->annualInterestConverted = this->convertAnnualInterest(this->annualInterest);
    initializeMatrix();
  }

  // Getters
  double getInitialInvestment() const {return initialInvestment;}
  double getMonthlyDeposit() const {return monthlyDeposit;}
  double getAnnualInterest() const {return annualInterest;}
  double getNumberOfYears() const {return numberOfYears;}

  // additional data storage
  std::vector<double> intitialInvestmentValues;
  std::vector<double> interestWithoutMonthlyDeposits;
  std::vector<double> interestWithMonthlyDeposits;

  // Setters

  void setInitialInvestment(double num) { initialInvestment = num;}
  void getMonthlyDeposit(double num) {monthlyDeposit = num;}
  void setAnnualInterest(double num) {annualInterest = num;}
  void setNumberOfYears(double num) {numberOfYears = num;}

  private:
  std::string name;
  double initialInvestment;
  double monthlyDeposit;
  double annualInterest;
  double numberOfYears;
  double annualInterestInPercent;
  double annualInterestConverted;
  // matrix to hold our data
  // two rows - 1 for:
  //              *Financial outcomes with monthly payments
  //              *Financial outcomes without monthly payments
  //
  // Year end balances // Year-earned Interest
  // Year end balances // Year-earned interest - based on monthly deposit value
  static const int rows = 2;
  static const int cols = 10;
  double matrix[rows][cols];

  void initializeMatrix() {
    // model of matrix info
    // [0] = initial investment
    // [1] = monthly deposit
    // [2] = annual interest
    // [3] = number of years

    matrix[0][0] = this->getInitialInvestment();
    matrix[0][1] = this->getMonthlyDeposit();
    matrix[0][2] = this->getAnnualInterest();
    matrix[0][3] = this->getNumberOfYears();
  }



  double convertAnnualInterest(double& num)
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

