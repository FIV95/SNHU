#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <vector>
#include "product.h"
#include <unordered_map>

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

    virtual std::vector<Product> getVectorContent() const = 0;
    virtual std::unordered_map<std::string, int> getHashTableContent() const = 0;
    virtual void setVectorContent(const std::vector<Product> &products) = 0;
    virtual void setHashTableContent(const std::unordered_map<std::string, int>) = 0;
};

#endif // DOCUMENT_H
