#ifndef INPUTDOCUMENT_H
#define INPUTDOCUMENT_H

#include <string>
#include <vector>
#include "document.h"
#include "product.h"

class InputDocument : public Document
{
  public:
    InputDocument(std::string path, int osType);

    std::string getDocumentTitle() const override;
    void setDocumentTitle(const std::string &title) override;

    std::vector<Product> getDocumentContent() const override;
    void setDocumentContent(const std::vector<Product> &products) override;
};

#endif // INPUTDOCUMENT_H