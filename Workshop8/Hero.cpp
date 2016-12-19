// OOP244 Workshop 8: Derived Classes
// Hero.cpp
// Version 1.0
// Date	2016/11/09
// Author	Alena Mitrakhovich
// amitrakhovich@myseneca.ca
// 115 297 152
/////////////////////////////////////////////////////

#include "Hero.h"
#include <cstring>
#include <iostream>
using namespace std;

Hero::Hero() {
  setEmpty();
}

void Hero::setEmpty() {
  name_[0] = '\0';
  strength_ = 0;
}

Hero::Hero(const char* name, double strength) {
  strncpy(name_, name, 21);
  strength_ = strength;
  if (strength_ < 0) {
    setEmpty();
  }
}

Hero::~Hero() {
  ;
}

bool Hero::isEmpty() const {
  bool ret;
  if (name_[0] != '\0') {
    ret = false;
  }
  else
    ret = true;

  return ret;
}

double Hero::getStrength() const {
  double ret;
  if (!isEmpty()) {
    ret = strength_;
  }
  else
    ret = 0.0;

  return ret;
}

void Hero::display(std::ostream& os)const{
  if (!isEmpty()) {
    os << name_ << " - " << strength_ << endl;
  }
  else {
    ;
  }
}

void Hero::operator-=(double strength) {
  if (strength > strength_) {
    strength_ = 0.0;
  }
  else {
    strength_ -= strength;
  }
}

void Hero::operator+=(double strength) {
  strength_ += strength;
}

bool operator<(const Hero& a, const Hero& b) {
  bool ret;
  if (a.getStrength() < b.getStrength()) {
    ret = true;
  }

  else
    ret = false;

  return ret;
}