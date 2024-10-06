#include <iostream>
#include <array>
#include "app.h"
#include "investment.h"

int main () {
    App app;
    app.PrintMenu();
    std::array<double, 4> results = app.GetInput();
    app.ConfirmResults(results);
    Investment investment(results[0], results[1], results[2], results[3]);
    investment.displayMonthlyResultsWithDeposits();
    return 0;
}
