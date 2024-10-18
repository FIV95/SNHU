#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <vector>
#include "product.h"

class Document {
protected:
    std::string _path;
    std::string _title;
    std::vector<Product> _products;

public:
    Document(const std::string& path, int osType); // Constructor declaration
    virtual ~Document() = default;

    virtual std::string getTitle() const = 0;
    virtual std::string getPath() const = 0;
    virtual void setTitle(const std::string &title) = 0;
    virtual void setPath(const std::string &path) = 0;

    virtual std::vector<Product> getContent() const = 0;
    virtual void setContent(const std::vector<Product> &products) = 0;
};

#endif // DOCUMENT_H
