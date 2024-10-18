#include "inputDocument.h"
using std::string;

// Default constructor
InputDocument::InputDocument() : Document("", 0), _osType(0) {
}

// Parameterized constructor
InputDocument::InputDocument(std::string path, int osType)
    : Document(path, osType), _osType(osType) {
}

// Override getTitle
std::string InputDocument::getTitle() const {
    return this->_title;
}

// Override getPath
std::string InputDocument::getPath() const {
    return this->_path;
}

// Override setTitle
void InputDocument::setTitle(const std::string &title) {
    std::string str(title);
    char pathSymbol = (_osType == 1) ? '\\' : '/'; // Use '\\' for Windows, '/' for Unix

    // Find last occurrence of pathSymbol and '.'
    int pathIndex = str.find_last_of(pathSymbol);

    // Extract the title
    std::string newTitle = str.substr(pathIndex + 1);

    this->_title = newTitle;
}
// Override setPath
void InputDocument::setPath(const std::string &path) {
    this->_path = path;
}

// Override getContent
std::vector<Product> InputDocument::getContent() const {
    return this->_products;
}

// Override setContent
void InputDocument::setContent(const std::vector<Product> &products) {
    this->_products = products;
}

