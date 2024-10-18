#include "validation.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <filesystem>
#include <array>

namespace fs = std::__fs::filesystem;

bool Validation::isValidInt(const std::string &input)
{
    std::istringstream iss(input);
    int i;
    char c;
    return iss >> i && !(iss >> c);
}

bool Validation::isValidChar(const std::string &input)
{
    if (input.length() == 1)
    {
        return true;
    }
    else
    {
        std::cout << "The input provided is not a single character" << std::endl;
        return false;
    }
}

bool Validation::intIsInMenuRange(const std::string &input)
{
    try
    {
        int i = std::stoi(input);
        if (i >= 1 && i <= 5)
        {
            return true;
        }
        else
        {
            std::cout << "The number provided is out of the valid range (1-5)" << std::endl;
            return false;
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "The input provided is not a number" << std::endl;
        return false;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "The number provided is out of range" << std::endl;
        return false;
    }
}

int Validation::osCheck()
{
#if defined(_WIN32) || defined(_WIN64)
    return 1; // Windows
#elif defined(__unix__) || defined(__unix) || defined(__linux__) || defined(__APPLE__)
    return 2; // Unix-based
#else
    return 0; // Unknown
#endif
}

bool Validation::isValidWindowsPath(const std::string &input) {
 // FIX ME - Implement the validation for Windows paths
    return true;
}

bool Validation::isValidUnixPath(const std::string &input) {
 // FIX ME - Implement the validation for Unix paths
    return true;
}

bool Validation::isValidPath(const std::string &input) {

    if (fs::exists(input)) {
        if (fs::is_regular_file(input)) {
            return true;
        }
        else {
            std::cout << "The path provided does not return a regular file type." << std::endl;
            return false;
        }
    } else {
        std::cout << "The path provided does not exist" << std::endl;
        return false;
    }
}
