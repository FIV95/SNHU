#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>
#include <sstream>


class Validation
{
  public:
  bool intIsInMenuRange(const std::string &input);
  bool isValidChar(const std::string &input);
  bool isValidInt(const std::string &input);
  bool isWindowsOS();
  bool isUnixBasedOS();
  bool isValidWindowsPath(const std::string &input);
  bool isValidUnixPath(const std::string &input);
  int osCheck();
  
};

#endif