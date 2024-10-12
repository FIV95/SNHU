#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <vector>

class Document
{
  // constructor
  Document(std::string path, int osType);

  protected:
  std::string path;
  std::string title;
  std::vector<Product> products;
  int osType; // 0 for Unix, 1 for Windows

  public: 
  std::string getDocumentTitle() const {return this->title;}
  void setDocumentTitle(std::string, &title);

  std::vector<Product> getDocumentContent() const {return this->products;}
  void setDocumentContent(vector<Product>);

};

#endif