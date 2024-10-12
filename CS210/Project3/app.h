#ifndef APP_H
#define APP_H

#include <string>
#include <vector>

class App
{
  private:
  bool running = true;
  bool hasDocument = false;
  char input;
  int osType;
  InputDocument currentDocument;
  std::string option1Results;

  public:

  // print methods
  void printMenu();
  void printOption1Results(std::string query);
  void printOption2Results(std::vector<Product> products);
  void printOption3Results(std::vector<Product> products);

  // result 1 methods
  std::string calculateOption1(std::string query);
  void setOption1Results(std::string result);
  std::string getOption1Results() {return this->option1Results;}

  // document related methods
  InputDocument getCurrentDocument() const {return this->currentDocument;}
  void setCurrentDocument(std::string path);
  bool hasDocument() const {return this->hasDocument;}
  void setHasDocument(bool hasDocument);

  OutputDocument createOutputDocument(std::vector<Product>);

  char getInput() const {return this->input;}
  void setInput(char input);
  bool isRunning() const {return this->running;}
  void setRunning(bool);
  
};

#endif