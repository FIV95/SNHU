#include "validation.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <filesystem>
#include <array>

bool Validations::isValidInt(const std::string &input)
{
  std::istringstream iss(input);
  int i;
  char c;
  return iss >> i && !(iss >> c);
}

bool Validations::isValidChar(const std::string &input)
{
  return input.length() == 1;
}

bool Validations::intIsInMenuRange(const std::string &input)
{
  int i = std::stoi(input);
  return i >= 1 && i <= 5;
}

bool Validations::isWindowsOS()
{
  if (defined(_WIN32) || defined(_WIN64))
  {
    return true;
  }
  else
  {
    return false;
  }

bool Validations::isUnixBasedOS()
{
  if (defined(__unix__) || defined(__unix) || defined(__linux__) || defined(__linux) || defined(__APPLE__))
  {
    return true;
  }
  else
  {
    return false;
  }
}
  bool Validations::isValidWindowsPath(const std::string &input)
  {
    // check if the path is valid
  }

int Validations::osCheck()
{
  if (Validations::isWindowsOS())
  {
    return 1;
  }
  else if (Validations::isUnixBasedOS())
  {
    return 0;
  }
  else
  {
    return -1;
  }
}
