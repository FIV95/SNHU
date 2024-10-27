#include "documentProccessor.h"
#include "inputDocument.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <unordered_map>

void DocumentProcessor::readDocument(InputDocument *inputDocument)
{
    std::ifstream file;
    // hash table to hold <string, int> pairs
    std::unordered_map<std::string, int> documentHashTableContent;
    // Declare variable for the document content
    std::vector<Product> documentVectorContent;
    std::string line;
    file.open(inputDocument->getPath());

    // Check if the file is open
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << inputDocument->getPath() << std::endl;
        return;
    }

    file >> line;
    while (!file.fail())
    {
        // Further logic for reading document...
        if (documentHashTableContent.find(line) == documentHashTableContent.end())
        {
            documentHashTableContent[line] = 1;
        }
        else
        {
            documentHashTableContent[line]++;
        }
        file >> line;
    }

    // Close the file
    file.close();
    if (!file.eof())
    {
        std::cout << "Input failure before reaching end of file." << std::endl;
    }
    // now that we have our hashtable / frequency chart we can populate our Product Vector
    for (const auto &pair : documentHashTableContent)
    {
        std::string name = pair.first;
        int qty = pair.second;
        Product product;
        product.setName(name);
        product.setQty(qty);
        // push new product into our vector of Products
        documentVectorContent.push_back(product);
    }

    file.close();
    inputDocument->setVectorContent(documentVectorContent);
    inputDocument->setHashTableContent(documentHashTableContent);
    return;
}

int DocumentProcessor::calculateOption1(std::string query, InputDocument *InputDocument)
{
    std::unordered_map<std::string, int> documentHashTableContent = InputDocument->getHashTableContent();
    if (documentHashTableContent.find(query) != documentHashTableContent.end())
    {
        return documentHashTableContent[query];
    }
    else
    {
        return 0;
    }
}
