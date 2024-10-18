#include "app.h"
#include "validation.h"
#include "inputDocument.h"
#include "outputDocument.h"
#include <iostream>

int main()
{
    App app;

    while (app.isRunning())
    {
        app.printMenu();
        app.promptForInput();

        if (app.getInput() == '1')
        {
            // attempt to create input document
            std::string path;
            do
            {
                std::cout << "Please enter the path to the input file: ";
                std::cin >> path;
            }
            while (!Validation::isValidPath(path));
            InputDocument* inputDocument = new InputDocument(path, app.getOsType());
            inputDocument->setTitle(path);
            app.setCurrentDocument(inputDocument);
            app.setHasDocument(true);

        }
        if (app.getInput() == '2')
        {
            // first check if document is loaded
            if (!app.hasDocument())
            {
                std::cout << "No document loaded. Please load a document first." << std::endl;
                continue;
            }
            // FIX ME implement option 2
        }
        if (app.getInput() == '3')
        {
            // first check if document is loaded
            if (!app.hasDocument())
            {
                std::cout << "No document loaded. Please load a document first." << std::endl;
                continue;
            }
            // FIX ME implement option 3
        }
        if (app.getInput() == '4')
        {
            // first check if document is loaded
            if (!app.hasDocument())
            {
                std::cout << "No document loaded. Please load a document first." << std::endl;
                continue;
            }
            // FIX ME implement option 4
        }
        if (app.getInput() == '5')
        {
            app.setRunning(false);
        }

    }

    return 0;
}
