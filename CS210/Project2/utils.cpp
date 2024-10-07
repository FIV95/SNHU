#include "utils.h"
#include <sstream>

// Function to check if a string can be turned into a valid double (like 12.34)
bool isValidDouble(const std::string& str) {
    std::istringstream iss(str);  // Turn the string into a stream so we can work with it
    double d;  // This will store the number if the string is valid
    char c;  // Just a placeholder to see if there’s any extra junk after the number

    // Try to read the number and check if there’s anything left after
    // It returns true if the whole string is a valid double and nothing else is left
    return iss >> d && !(iss >> c);
}

// Function to check if a string is a valid integer (like 123)
bool isValidInt(const std::string& str) {
    std::istringstream iss(str);  // Again, turn the string into a stream
    int i;  // This will store the integer if the string is valid
    char c;  // Another placeholder to catch any leftovers

    // Try to read the integer and make sure there’s no extra stuff after it
    return iss >> i && !(iss >> c);  // Returns true if it's a valid integer with no extra characters
}
