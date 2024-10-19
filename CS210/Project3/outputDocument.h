#ifndef OUTPUTDOCUMENT_H
#define OUTPUTDOCUMENT_H

#include "document.h"
#include "product.h"
#include <vector>
#include <unordered_map>
#include <string>

class OutputDocument : public Document
{
private:
  std::string _title;
  std::string _path;
  std::vector<Product> _products;
  std::unordered_map<std::string, int> _hashTable;

public:
  OutputDocument();
  OutputDocument(std::string path, int osType, std::vector<Product> products);

  std::string getTitle() const override;
  std::string getPath() const override;

  void setPath(const std::string &path) override;
  void setTitle(const std::string &title) override;

  // Override: Return a copy of the vector to match the pure virtual function
  std::vector<Product> getVectorContent() const override;

  // Additional methods for reference access (for internal usage)
  std::vector<Product>& getVectorContentRef();
  const std::vector<Product>& getVectorContentRef() const;

  void setVectorContent(const std::vector<Product> &products) override;

  std::unordered_map<std::string, int> getHashTableContent() const override;
  void setHashTableContent(const std::unordered_map<std::string, int> hashTable) override;

  void sortProductsByName();
  void sortProductsByQtyFrequency();
  int partitionByName(std::vector<Product> &vector, int low, int high);
  void recursivelySortProductsByName(std::vector<Product> &vector, int low, int high);
  int partitionByQty(std::vector<Product> &vector, int low, int high);
  void recursivelySortProductsByQtyFrequency(std::vector<Product> &vector, int low, int high);

  void createBackup();
};

#endif // OUTPUTDOCUMENT_H
