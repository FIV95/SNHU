#include <iostream>
#include <array>
#include "app.h"
#include "investment.h"

int main () {
    App app;
    app.PrintMenu();
    std::array<double, 4> results = app.GetInput();
    while (app.isRunning()) {
        app.ConfirmResults(results);
        if (!app.isRunning()) {
            break;
        }
        Investment investment(results[0], results[1], results[2], results[3]);
        app.displayResultsWithMonthlyDeposits(investment.getResultsWithMonthlyPayments());
        app.displayResultsWithoutMonthlyDeposits(investment.getResultsWithoutMonthlyPayments());
    }
    return 0;
}
