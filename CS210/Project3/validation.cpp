#include "validation.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <filesystem>
#include <array>

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

        bool Validation::isWindowsOS()
        {
#if defined(_WIN32) || defined(_WIN64)
            return true;
#else
            return false;
#endif
        }

        bool Validation::isUnixBasedOS()
        {
#if (defined(__unix__) || defined(__unix) || defined(__linux__) || defined(__linux) || defined(__APPLE__))
            {
                return true;
            }
#else
            {
                return false;
#endif
        }
        bool Validation::isValidWindowsPath(const std::string &input)
        {
            // check if the path is valid
        }

        int Validation::osCheck()
        {
            if (Validation::isWindowsOS())
            {
                return 1;
            }
            else if (Validation::isUnixBasedOS())
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
