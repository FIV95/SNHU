#include "DocumentProcessor.h"
#include "InputDocument.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <filesystem>
#include <array>

// Constructor
DocumentProcessor::DocumentProcessor(InputDocument &currentDocument) : _currentDocument(currentDocument)
{
}

std::string DocumentProcessor::setOption1(std::string query)
{
    std::string result = "";

    // Declare variable for the document content
    std::vector<Product> documentContent = _currentDocument.getContent();

    // Further logic for processing query...
    return result;
}
