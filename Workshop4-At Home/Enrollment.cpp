// OOP244 Workshop 4: Constructors 
// File: Enrollment.cpp
// Version: 1.0
// Date: October 7, 2016
// Author: Alena Mitrakhovich
// amitrakhovich@myseneca.ca
// 115 297 152
// Description:
// Specifying functions related to enrollment 
/////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "Enrollment.h"
using namespace std;

namespace ict {
  Enrollment::Enrollment() {
    setEmpty();
  }

  Enrollment::Enrollment(const char* name, const char* code, int year, int semester, int time) {
    if (name != NULL && name[0] != '\0' && code != NULL && code[0] != '\0' && year >= 2015 && semester > 0 && semester < 4 && time > 0 && time < 6) {
      strcpy(name_, name);
      strcpy(code_, code);
      year_ = year;
      semester_ = semester;
      slot_ = time;
      enrolled_ = false;
    }
    else
      setEmpty();
  }

  Enrollment::~Enrollment() {
    ;
  }

  void Enrollment::set(const char* name, const char* code, int year, int semester, int time, bool enrolled) {
    if (name != NULL && name[0] != '\0' && code != NULL && code[0] != '\0' && year >= 2015 && semester > 0 && semester < 4 && time > 0 && time < 6) {
      strcpy(name_, name);
      strcpy(code_, code);
      year_ = year;
      semester_ = semester;
      slot_ = time;
      enrolled_ = enrolled;
    }
    else
      setEmpty();
  }

  bool Enrollment::hasConflict(const Enrollment &other) const {
    bool conflict = false;

    if (isValid() || other.isValid()) {
      if (other.year_ == year_ && other.semester_ == semester_ && other.slot_ == slot_) {
        conflict = true;
      }
    }
    else {
      conflict = false;

    }

    return conflict;
  }

  //done
  bool Enrollment::isValid()const {
    return name_ && name_[0];
  }
  //done
  void Enrollment::setEmpty() {
    name_[0] = 0;
    code_[0] = 0;
    year_ = 0;
    semester_ = 0;
    slot_ = 0;
    enrolled_ = false;
  }
  // done
  bool Enrollment::isEnrolled() const {
    return enrolled_;
  }

  // done
  void Enrollment::display(bool nameOnly)const {
    if (isValid()) {
      cout << name_;
      if (!nameOnly) {
        cout << endl << code_ << ", Year: " << year_ << " semester: " << semester_ << " Slot: " << slot_ << endl;
        cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
      }
    }
    else {
      cout << "Invalid enrollment!" << endl;
    }
  }

  void Enrollment::withdraw() {
    enrolled_ = false;
  }

  int Enrollment::enrol(const Enrollment* enrollments, int size) {
    int counting;
    bool flag = false;
    int sequence = 0;

    for (counting = 0; counting < size; counting ++) {
      if (enrollments[counting].year_ == year_ && enrollments[counting].semester_ == semester_ && enrollments[counting].slot_ == slot_) {
        sequence = counting + 1;
        counting = size + 10;
        flag = false;
      }
      else {
        flag = true;
        enrolled_ = true;
      }
    }

    if (flag == true) {
      sequence = 0;
    }

    return sequence;
  }

}