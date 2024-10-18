#ifndef OUTPUTDOCUMENT_H
#define OUTPUTDOCUMENT_H

#include <string>
#include <vector>
#include "document.h"
#include "product.h"

class OutputDocument : public Document
{
  public:
    OutputDocument(std::string path);

    std::string getTitle() const override;
    std::string getPath() const override;

    void setPath(const std::string &path) override;
    void setTitle(const std::string &title) override;

    std::vector<Product> getContent() const override;
    void setContent(const std::vector<Product> &products) override;

    void sortProductsByName(std::vector<Product> &products);
    void sortProductsByQtyFrequency(std::vector<Product> &products);
};

#endif // OUTPUTDOCUMENT_H
