#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <vector>

class Product;

class Document
{
  public:
    // Constructor
    Document(std::string path, int osType);

    // Pure virtual functions (making this an abstract class)
    virtual std::string getDocumentTitle() const = 0;
    virtual void setDocumentTitle(const std::string &title) = 0;

    virtual std::vector<Product> getDocumentContent() const = 0;
    virtual void setDocumentContent(const std::vector<Product> &products) = 0;

  protected:
    std::string path;
    std::string title;
    std::vector<Product> products;
    int osType; // 0 for Unix, 1 for Windows
};

#endif // DOCUMENT_H