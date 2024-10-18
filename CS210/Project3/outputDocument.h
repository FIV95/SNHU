#ifndef OUTPUTDOCUMENT_H
#define OUTPUTDOCUMENT_H

#include <string>
#include <vector>
#include "document.h"
#include "product.h"
#include <unordered_map>

class OutputDocument : public Document
{
  public:
    OutputDocument(std::string path);

    std::string getTitle() const override;
    std::string getPath() const override;

    void setPath(const std::string &path) override;
    void setTitle(const std::string &title) override;

    std::vector<Product> getVectorContent() const override;
    void setVectorContent(const std::vector<Product> &products) override;
    std::unordered_map<std::string, int> getHashTableContent() const override;
    void setHashTableContent(const std::unordered_map<std::string, int>) override;


    void sortProductsByName(std::vector<Product> &products);
    void sortProductsByQtyFrequency(std::vector<Product> &products);
};

#endif // OUTPUTDOCUMENT_H
