// Final Project Milestone 2
// File	Error.cpp
// Version 1.0
// Date	November 5, 2016
// Author	Alena Mitrakhovich
// 115 297 152
// amitrakhovich@myseneca.ca
////////////////////////////

#include "Error.h"
#include <cstring>
#include <iostream>
namespace ict {
  Error::Error() {
    message_ = nullptr;
  }

  Error::Error(const char* Error) {
    message_ = nullptr;
    message(Error);
  }

  /*Error::Error(const Error& em) {
  ;
  }*/

  /*Error& Error::operator=(const Error& em) {
  ;
  }*/

  Error& Error::operator=(const char* errorMessage) {
    clear();
    message(errorMessage);
    return *this;
  }

  Error::~Error() {
    delete message_;
  }

  void Error::clear() {
    delete message_;
    message_ = nullptr;
  }

  bool Error::isClear() const {
    bool ret = false;
    if (message_ == nullptr) {
      ret = true;
    }
    return ret;
  }

  void Error::message(const char* value) {
    delete message_;
    message_ = new char[strlen(value) + 1];
    strcpy(message_, value);
  }

  const char* Error::message()const {
    return message_;
  }

  std::ostream& operator<<(std::ostream& os, const Error& e) {
    if (e.isClear()) {
      ;
    }
    else {
      os << e.message();
    }
    return os;
  }

}