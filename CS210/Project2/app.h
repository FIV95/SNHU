#ifndef APP_H
#define APP_H

#include <array>
#include <string>
#include <vector>

class App {
    public:
        App();
        void PrintMenu();
        std::array<double, 4> GetInput();
        void PrintConfirmChoices();
        void ConfirmResults(std::array<double, 4>& results);
        void displayResultsWithMonthlyDeposits(const std::vector<std::vector<double> >& resultsWithMonthlyPayments);
        void displayResultsWithoutMonthlyDeposits(const std::vector<std::vector<double> >& resultsWithoutMonthlyPayments);
        void Quit();
        bool isRunning() const;

    private:
        bool m_running;
};

#endif
