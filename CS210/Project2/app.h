#ifndef APP_H
#define APP_H

#include <array>
#include <string>
#include <vector>

// App class declaration
class App {
    public:
        // Constructor
        App();

        // Function to print the main menu
        void PrintMenu();

        // Function to get user input for initial investment, monthly deposit, annual interest, and number of years
        std::array<double, 4> GetInput();

        // Function to display confirmation options for the user to change the entered values or continue
        void PrintConfirmChoices();

        // Function to confirm the user input and allow corrections if needed
        void ConfirmResults(std::array<double, 4>& results);

        // Function to display the results of the investment with monthly deposits
        void displayResultsWithMonthlyDeposits(const std::vector<std::vector<double> >& resultsWithMonthlyPayments);

        // Function to display the results of the investment without monthly deposits
        void displayResultsWithoutMonthlyDeposits(const std::vector<std::vector<double> >& resultsWithoutMonthlyPayments);

        // Function to quit the application
        void Quit();

        // Function to check if the application is still running
        bool isRunning() const;

    private:
        // Boolean variable to track whether the application is running or not
        bool m_running;
};

#endif  // End of include guard
