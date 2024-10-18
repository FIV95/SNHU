#ifndef DOCUMENTPROCESSOR_H
#define DOCUMENTPROCESSOR_H

#include <string>
#include <vector>
#include "InputDocument.h"
#include "OutputDocument.h"
#include "Product.h"

class DocumentProcessor
{
  private:
    InputDocument &_currentDocument; // Prefixing with _ for private member

  public:
    DocumentProcessor(InputDocument &currentDocument);
    std::string setOption1(std::string query); // Methods should follow camelCase
    std::vector<Product> setOption2();
    std::vector<Product> setOption3();
};

#endif // DOCUMENTPROCESSOR_H
