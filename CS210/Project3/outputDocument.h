#ifndef OUTPUTDOCUMENT_H
#define OUTPUTDOCUMENT_H

#include <string>
#include <vector>

class OutputDocument : public Document
{
  public:
  OutputDocument(std::string path, int osType);
  void sortProductsByName(vector<Product> &products);
  void sortProductsByQtyFrequency(vector<Product> &products);
};