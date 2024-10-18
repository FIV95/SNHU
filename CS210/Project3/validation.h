#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>
#include <sstream>

class Validation
{
  public:
    static bool intIsInMenuRange(const std::string &input);
    static bool isValidChar(const std::string &input);
    static bool isValidInt(const std::string &input);
    static bool isValidWindowsPath(const std::string &input);
    static bool isValidUnixPath(const std::string &input);
    static bool isValidPath(const std::string &input);
    static int osCheck();
};

#endif // VALIDATION_H
