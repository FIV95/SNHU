#ifndef INPUTDOCUMENT_H
#define INPUTDOCUMENT_H

#include <string>
#include <vector>
#include "document.h"
#include "product.h"
#include <unordered_map>

class InputDocument : public Document
{
  private:
    int _osType;
    std::vector<Product> _products;
    std::unordered_map<std::string, int> _hashTable;
  public:
    InputDocument();
    InputDocument(std::string path, int osType);

    std::string getTitle() const override;
    std::string getPath() const override;
    void setTitle(const std::string &title) override;
    void setPath(const std::string &path) override;

    std::vector<Product> getVectorContent() const override;
    std::unordered_map<std::string, int> getHashTableContent() const override;

    void setVectorContent(const std::vector<Product> &products) override;
    void setHashTableContent(const std::unordered_map<std::string, int>) override;
    void setOsType(int osType) { this->_osType = osType; }
    int getOsType() const { return this->_osType; }
};

#endif // INPUTDOCUMENT_H
