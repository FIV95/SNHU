#include "utils.h"
#include <sstream>

bool isValidDouble(const std::string& str) {
    std::istringstream iss(str);
    double d;
    char c;
    return iss >> d && !(iss >> c); // Check if the entire string is consumed and is a valid double
}

bool isValidInt(const std::string& str) {
    std::istringstream iss(str);
    int i;
    char c;
    return iss >> i && !(iss >> c); // Check if the entire string is consumed and is a valid int
}
