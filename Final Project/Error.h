// Final Project Milestone 2
// File	Error.h
// Version 1.0
// Date	November 5, 2016
// Author	Alena Mitrakhovich
// 115 297 152
// amitrakhovich@myseneca.ca
////////////////////////////

#ifndef SICT_ERROR_H__
#define SICT_ERROR_H__
#include <iostream>
namespace ict {
  class Error {
    char* message_;
  public:
    Error();
    Error(const char* Error);
    Error(const Error& em) = delete;
    Error& operator=(const Error& em) = delete;
    Error& operator=(const char* errorMessage);
    virtual ~Error();
    void clear();
    bool isClear() const;
    void message(const char* value);
    const char* message() const;
  };

  // operator<< overload prototype
  std::ostream& operator<<(std::ostream& os, const Error& e);
}
#endif