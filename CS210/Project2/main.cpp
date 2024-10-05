#include <iostream>
#include <array>
#include "app.h"

int main () {
    App app;
    app.PrintMenu();
    std::array<double, 4> results = app.GetInput();
    app.ConfirmResults(results);
    return 0;
}
