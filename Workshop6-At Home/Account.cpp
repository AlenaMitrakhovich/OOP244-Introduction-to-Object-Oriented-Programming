// OOP244 Workshop 6: operators
// File: Account.cpp
// Version: 1.0
// Date: October 26, 2016
// Author: Alena Mitrakhovich
// amitrakhovich@myseneca.ca
// 115 297 152

#include <iomanip>
#include "Account.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace ict {

  void Account::display(bool gotoNewline)const {
    cout << (name_[0] ? name_ : "No Name") << ": $" << setprecision(2) << fixed << balance_;
    if (gotoNewline) cout << endl;
  }


  Account::Account() {
    name_[0] = 0;
    balance_ = 0;
  }
  Account::Account(double balance) {
    name_[0] = 0;
    balance_ = balance;
  }
  Account::Account(const char name[], double balance) {
    strcpy(name_, name);
    balance_ = balance;
  }

  Account& Account::operator+=(const Account& x) {
    balance_ += x.balance_;

    return *this;
  }

  Account& Account::operator=(const char str[]) {
    strncpy(name_, str, 40);
    return *this;
  }

  ostream& operator<<(ostream& os, const Account& z) {
    z.display(false);

    return os;
  }

  Account Account::operator+(const Account& x) {
    Account ret = *this;
    ret.name_[0] = '\0';
    ret.balance_ = getBalance(x) + getBalance(*this);
    return ret;
  }

  double operator+=(double &balance, const Account& y) {
    Account copy = y;
    balance += copy.getBalance(copy);
    return balance;
  }
  
  double Account::getBalance(const Account& x) {
    double z;
    z = x.balance_;
    return z;
  }
}