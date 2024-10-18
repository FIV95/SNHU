#ifndef INPUTDOCUMENT_H
#define INPUTDOCUMENT_H

#include <string>
#include <vector>
#include "document.h"
#include "product.h"

class InputDocument : public Document
{
  private:
    int _osType;
  public:
    InputDocument();
    InputDocument(std::string path, int osType);

    std::string getTitle() const override;
    std::string getPath() const override;
    void setTitle(const std::string &title) override;
    void setPath(const std::string &path) override;

    std::vector<Product> getContent() const override;
    void setContent(const std::vector<Product> &products) override;
    void setOsType(int osType) { this->_osType = osType; }
    int getOsType() const { return this->_osType; }
};

#endif // INPUTDOCUMENT_H
