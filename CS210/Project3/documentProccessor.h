#ifndef DOCUMENTPROCESSOR_H
#define DOCUMENTPROCESSOR_H

#include <string>
#include <vector>
#include "inputDocument.h"
#include "outputDocument.h"
#include "product.h"

class DocumentProcessor
{
  private:
    InputDocument &_currentDocument; // Prefixing with _ for private member

  public:
    static int setOption1(std::string query, InputDocument* inputDocument);
    static void readDocument(InputDocument* inputDocument);
    static std::vector<Product> setOption2();
    static std::vector<Product> setOption3();
};

#endif // DOCUMENTPROCESSOR_H
