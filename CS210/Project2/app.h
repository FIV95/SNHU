#ifndef APP_H
#define APP_H

#include <array>
#include <string>

class App {
    public:
        App();
        void PrintMenu();
        std::array<double, 4> GetInput();
        void PrintConfirmChoices();
        void ConfirmResults(std::array<double, 4>& results);
        void Quit();

    private:
        bool running;

};


#endif
