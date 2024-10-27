#include "outputDocument.h"
#include "document.h"
#include "product.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <filesystem>

// Default constructor
OutputDocument::OutputDocument() : Document("", 0) {}

// Parameterized constructor
OutputDocument::OutputDocument(std::string path, int osType, std::vector<Product> products) : Document(path, osType)
{
    this->setTitle("frequency.dat");
    this->setPath(path);
    this->setVectorContent(products);
    this->sortProductsByQtyFrequency();
}

// Override getTitle
std::string OutputDocument::getTitle() const
{
    return this->_title;
}

// Override getPath
std::string OutputDocument::getPath() const
{
    return this->_path;
}

// Override setTitle
void OutputDocument::setTitle(const std::string &title)
{
    this->_title = title;
}

void OutputDocument::setPath(const std::string& path)
{
    std::filesystem::path absolutePath = std::filesystem::absolute(path);
    this->_path = absolutePath.string() + std::filesystem::path::preferred_separator + this->getTitle();
}
// Override getVectorContent() to return a reference
std::vector<Product>& OutputDocument::getVectorContentRef()
{
    return this->_products;
}

// Const version if you need read-only access
const std::vector<Product>& OutputDocument::getVectorContentRef() const
{
    return this->_products;
}

// Override getVectorContent
std::vector<Product> OutputDocument::getVectorContent() const
{
    return this->_products;  // Return a copy of the vector
}

// Override setVectorContent
void OutputDocument::setVectorContent(const std::vector<Product> &products)
{
    this->_products = products;
}

// Override getHashTableContent
std::unordered_map<std::string, int> OutputDocument::getHashTableContent() const
{
    return this->_hashTable;
}

// Override setHashTableContent
void OutputDocument::setHashTableContent(const std::unordered_map<std::string, int> hashTable)
{
    this->_hashTable = hashTable;
}

// Sort products by name
void OutputDocument::sortProductsByName()
{
    std::vector<Product>& vector = this->getVectorContentRef();
    recursivelySortProductsByName(vector, 0, vector.size() - 1);

    // Debug print the vector after sorting
    std::cout << "Products sorted by name:" << std::endl;
    for (const auto& product : vector) {
        std::cout << "Name: " << product.getName() << ", Qty: " << product.getQty() << std::endl;
    }
}

// Sort products by quantity frequency
void OutputDocument::sortProductsByQtyFrequency()
{
    std::vector<Product>& vector = this->getVectorContentRef();
    recursivelySortProductsByQtyFrequency(vector, 0, vector.size() - 1);

}

// Partition by name for quicksort
int OutputDocument::partitionByName(std::vector<Product> &vector, int low, int high)
{
    std::string pivot = vector[low].getName();
    int i = low - 1;  // Set i to one position before low
    int j = high + 1; // Set j to one position after high

    while (true)
    {
        // Move i to the right while elements are less than the pivot
        do {
            i++;
        } while (i <= high && vector[i].getName() < pivot);

        // Move j to the left while elements are greater than the pivot
        do {
            j--;
        } while (j >= low && vector[j].getName() > pivot);

        // If i and j cross, return the partition index
        if (i >= j)
        {
            return j;
        }

        // Swap elements at i and j
        std::swap(vector[i], vector[j]);
    }
}


// Partition by quantity for quicksort
int OutputDocument::partitionByQty(std::vector<Product> &vector, int low, int high)
{
    int pivot = vector[low].getQty(); // Use the first element as the pivot
    int i = low - 1;  // Set i to one position before low
    int j = high + 1; // Set j to one position after high

    while (true)
    {
        // Move i to the right while elements are greater than the pivot (for descending sort)
        do {
            i++;
        } while (i <= high && vector[i].getQty() > pivot);

        // Move j to the left while elements are less than the pivot
        do {
            j--;
        } while (j >= low && vector[j].getQty() < pivot);

        // If i and j cross, return the partition index
        if (i >= j)
        {
            return j;
        }

        // Swap elements at i and j
        std::swap(vector[i], vector[j]);
    }
}


// Recursively sort products by name
void OutputDocument::recursivelySortProductsByName(std::vector<Product> &vector, int low, int high)
{
    if (low < high)
    {
        int p = partitionByName(vector, low, high);
        recursivelySortProductsByName(vector, low, p);       // Sort the left partition
        recursivelySortProductsByName(vector, p + 1, high);  // Sort the right partition
    }
}

void OutputDocument::recursivelySortProductsByQtyFrequency(std::vector<Product> &vector, int low, int high)
{
    if (low < high)
    {
        int p = partitionByQty(vector, low, high);
        recursivelySortProductsByQtyFrequency(vector, low, p);      // Sort the left partition
        recursivelySortProductsByQtyFrequency(vector, p + 1, high); // Sort the right partition
    }
}



// Create a backup of the products
void OutputDocument::createBackup()
{
    this->sortProductsByQtyFrequency();
    const std::vector<Product>& vector = this->getVectorContentRef();
    if (vector.empty())
    {
        std::cout << "No products to back up." << std::endl;
        return;
    }
    std::ofstream file(this->getTitle());
    if (file.is_open())
    {
        for (const auto& product : vector)
        {
            file << "Name: " << product.getName() << " || Quantity Sold: " << product.getQty() << std::endl;
        }
        file.close();
    }
    else
    {
        std::cout << "Failed to write to backup file" << std::endl;
    }
}