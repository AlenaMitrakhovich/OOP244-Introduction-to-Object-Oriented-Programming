// Final Project Milestone 1
// File	Date.cpp
// Version 1.0
// Date	2016/10/29
// Author	Alena Mitrakhovich
// 115 297 152
// amitrakhovich@myseneca.ca
// Description
// Implementing Date Class
//
/////////////////////////////////////////////////////////////////

// header files go here
#include "Date.h"
#include "wpgeneral.h"

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

namespace ict {
  // returns a unique value representing the date
  // this value is used to compare two dates
  int Date::value()const {
    return year_ * 372 + mon_ * 31 + day_;
  }

  // bool validate(), this is an optional private function
  // for validation logic and setting the _readErrorCode.
  // see the read() function description for more details

  // mdays():
  // returns the days of the month.
  // _mon value must be set for this function to work
  // if _mon is invalid, this function returns -1
  // leap years are considered in this logic
  int Date::mdays()const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
    mon--;
    return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
  }

  // constructors
  Date::Date() {
    year_ = 0;
    mon_ = 0;
    day_ = 0;
    readErrorCode_ = 500;
  }

  Date::Date(int year, int mon, int day) {
    year_ = year;
    mon_ = mon;
    day_ = day;
    readErrorCode_ = NO_ERROR;
  }

  Date::~Date() {
    ;
  }

  // member functions
  void Date::errCode(int errorCode) {
    readErrorCode_ = errorCode;
  }

  int Date::errCode() const {
    return readErrorCode_;
  }

  bool Date::bad() const {
    bool ret;
    if (readErrorCode_ != 0) {
      ret = true;
    }
    else
      ret = false;

    return ret;
  }

  // operators
  bool Date::operator==(const Date& D)const {
    bool ret;

    if (this->value() == D.value()) {
      ret = true;
    }
    else
      ret = false;
    return ret;
  }

  bool Date::operator!=(const Date& D)const {
    bool ret;
    if (this->value() != D.value()) {
      ret = true;
    }
    else
      ret = false;

    return ret;
  }

  bool Date::operator<(const Date& D)const {
    bool ret;
    if (this->value() < D.value()) {
      ret = true;
    }
    else
      ret = false;

    return ret;
  }

  bool Date::operator>(const Date& D)const {
    bool ret;
    if (this->value() > D.value()) {
      ret = true;
    }
    else
      ret = false;

    return ret;
  }

  bool Date::operator<=(const Date& D)const {
    bool ret;
    if (this->value() <= D.value()) {
      ret = true;
    }
    else
      ret = false;

    return ret;
  }

  bool Date::operator>=(const Date& D)const {
    bool ret;
    if (this->value() >= D.value()) {
      ret = true;
    }
    else
      ret = false;

    return ret;
  }

  // IO functions
  std::istream& Date::read(std::istream& istr) {
    /*char year[5];
    char mon[3];
    char day[3];*/

    Date temp = *this;

    /*istr.getline(year, 5, '/');
    temp.year_ = atoi(year);*/
    istr >> temp.year_;
    istr.ignore(1, '/');

    if (istr.fail()) {
      temp.readErrorCode_ = CIN_FAILED;
    }
    else
      temp.readErrorCode_ = NO_ERROR;

    /*istr.getline(mon, 3, '/');
    temp.mon_ = atoi(mon);*/
    istr >> temp.mon_;
    istr.ignore(1, '/');

    if (istr.fail()) {
      temp.readErrorCode_ = CIN_FAILED;
    }
    else
      temp.readErrorCode_ = NO_ERROR;

    /*istr.getline(day, 3, '\n');
    temp.day_ = atoi(day);*/
    istr >> temp.day_;

    if (istr.fail()) {
      temp.readErrorCode_ = CIN_FAILED;
    }
    else
      temp.readErrorCode_ = NO_ERROR;

    if (temp.readErrorCode_ == NO_ERROR) {

      if (temp.year_ > MAX_YEAR || temp.year_ < MIN_YEAR) {
        temp.readErrorCode_ = YEAR_ERROR;
      }
      else {
        if (temp.mon_ < 0 || temp.mon_ > 12) {
          temp.readErrorCode_ = MON_ERROR;
        }
        else {
          if (/*temp.day_ < 0 || temp.day_ > 31*/temp.day_ > temp.mdays() || temp.day_ < 0) {
            temp.readErrorCode_ = DAY_ERROR;
          }
        }
      }
    }
    *this = temp;
    //return reference to istream - istr object
    return istr;
  }

  std::ostream& Date::write(std::ostream& ostr) const {
    if (mon_ < 10 && day_ < 10) {
      ostr << year_ << "/" << '0' << mon_ << "/" << '0' << day_;
    }
    else if (mon_ < 10) {
      ostr << year_ << "/" << '0' << mon_ << "/" << day_;
    }
    else if (day_ < 10) {
      ostr << year_ << "/" << mon_ << "/" << '0' << day_;
    }
    else {
      ostr << year_ << "/" << mon_ << "/" << day_;
    }
    return ostr;
  }

  // non-memeber operator overloads
  std::ostream& operator<<(std::ostream& os, const Date& d) {
    d.write(os);
    return os;
  }

  std::istream& operator>>(std::istream& is, Date& d) {
    d.read(is);
    return is;
  }
}
