#ifndef OUTPUTDOCUMENT_H
#define OUTPUTDOCUMENT_H

#include <string>
#include <vector>
#include "document.h"
#include "product.h"

class OutputDocument : public Document
{
  public:
    OutputDocument(std::string path, int osType);

    std::string getDocumentTitle() const override;
    void setDocumentTitle(const std::string &title) override;

    std::vector<Product> getDocumentContent() const override;
    void setDocumentContent(const std::vector<Product> &products) override;

    void sortProductsByName(std::vector<Product> &products);
    void sortProductsByQtyFrequency(std::vector<Product> &products);
};

#endif // OUTPUTDOCUMENT_H