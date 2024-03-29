// OOP244 Workshop 6: operators
// File: Account.h
// Version: 1.0
// Date: October 26, 2016
// Author: Alena Mitrakhovich
// amitrakhovich@myseneca.ca
// 115 297 152

#ifndef ICT_ACCOUNT_H__
#define ICT_ACCOUNT_H__

#include <iostream>

namespace ict {
  class Account {
    char name_[41];
    double balance_;
  public:
    void display(bool gotoNewline = true)const;

    Account();
    Account(double balance);
    Account(const char name[], double balance = 0.0);
    Account& operator+=(const Account& x);
    Account& operator=(const char str[]);
    friend Account operator+(const Account& x, const Account& y);
  };

  std::ostream& operator<<(std::ostream& os, const Account& z);

};

#endif