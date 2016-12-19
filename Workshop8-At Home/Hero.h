// OOP244 Workshop 8: Derived Classes
// Hero.h
// Version 1.0
// Date	2016/11/09
// Author	Alena Mitrakhovich
// amitrakhovich@myseneca.ca
// 115 297 152
// OOP 244 Fardad Soleimanloo
/////////////////////////////////////////////////////

#ifndef ICT_HERO_H__
#define ICT_HERO_H__

#include <iostream>

class Hero {
  char name_[21];
  double strength_;
public:
  Hero();
  Hero(const char* name, double strength);
  ~Hero();
  void setEmpty();
  bool isEmpty() const;
  double getStrength() const;
  void display(std::ostream& os) const;
  void operator-=(double strength);
  void operator+=(double strength);
  const char* name()const;
};

bool operator<(const Hero& a, const Hero& b);

#endif
