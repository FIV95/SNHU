#ifndef APP_H
#define APP_H

#include <string>
#include <vector>
#include "inputDocument.h"
#include "outputDocument.h"
#include "product.h"

class App {
private:
    bool _running;
    bool _hasDocument;
    char _input;
    std::string _query;
    InputDocument* _currentDocument;
    int _osType;
    bool _queryComplete;
    int _option1Results;

public:
    App();

    // Print methods
    void printMenu();
    void printOption1Results(std::string query);
    void printOption2Results(std::vector<Product> products);
    void printOption3Results(std::vector<Product> products);
    void promptForQuery();
    void promptForQueryComplete();


    // Document related methods
    InputDocument* getCurrentDocument() const { return this->_currentDocument; }
    void setCurrentDocument(InputDocument* inputDocument);
    bool hasDocument() const { return this->_hasDocument; }
    void setHasDocument(bool hasDocument);

    OutputDocument createOutputDocument(std::vector<Product>);

    char getInput() const { return this->_input; } // Declare getInput method
    void setInput(const char &input); // Declare setInput method
    bool isRunning() const { return this->_running; }
    void setRunning(bool running);
    void setOsType(int osType) { this->_osType = osType; }
    int getOsType() const { return this->_osType; }
    std::string getQuery() const { return this->_query; }
    void setQuery(const std::string &query);

    void promptForInput();
    void setQueryComplete(bool queryComplete);
    bool getQueryComplete() const { return this->_queryComplete; }
    int getOption1Results() const { return this->_option1Results; }
    void setOption1Results(int result);
    std::vector<Product> getOption2Results() const { return this->_currentDocument->getVectorContent(); }
};

#endif // APP_H
