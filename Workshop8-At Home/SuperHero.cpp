// OOP244 Workshop 8: Derived Classes
// SuperHero.cpp
// Version 1.0
// Date	2016/11/11
// Author	Alena Mitrakhovich
// amitrakhovich@myseneca.ca
// 115 297 152
// OOP 244 Fardad Soleimanloo
/////////////////////////////////////////////////////

#include "SuperHero.h"
#include <cstring>
#include <iostream>

using namespace std;

SuperHero::SuperHero(const char* name, double strength, double mult): Hero(name, strength){
  mult_ = mult;
}

SuperHero::SuperHero(SuperHero& c): Hero(c.Hero::name(), c.Hero::getStrength()) {
  mult_ = c.mult_;
}

SuperHero::~SuperHero() {
  ;
}

double SuperHero::getStrength() const{
  double ret;

  ret =  this->Hero::getStrength();
  ret *= mult_;

  return ret;
}

void SuperHero::operator*=(SuperHero& b) {
  if (this->Hero::getStrength() < b.Hero::getStrength()) {
    b += this->Hero::getStrength();
  }
  else {
    *this += b.Hero::getStrength();
    b.setEmpty();
  }
}

void SuperHero::display(std::ostream& os) const {
  if (!isEmpty()) {
    os << "living superhero! ";
    this->Hero::display(os);
  }

  else {
    os << "deceased superhero!" << endl;
  }
}