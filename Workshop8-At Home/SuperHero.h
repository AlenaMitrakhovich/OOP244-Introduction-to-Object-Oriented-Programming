// OOP244 Workshop 8: Derived Classes
// SuperHero.h
// Version 1.0
// Date	2016/11/11
// Author	Alena Mitrakhovich
// amitrakhovich@myseneca.ca
// 115 297 152
// OOP 244 Fardad Soleimanloo
/////////////////////////////////////////////////////

#ifndef ICT_SUPERHERO_H__
#define ICT_SUPERHERO_H__

#include <iostream>

#include "Hero.h"

class SuperHero:public Hero{
  double mult_;
public:
  SuperHero(SuperHero& c);
  SuperHero(const char* name = "\0", double strength = 0, double mult = 0);
  double getStrength() const;
  void operator*=(SuperHero& b);
  void display(std::ostream& os) const;
  ~SuperHero();
};

#endif