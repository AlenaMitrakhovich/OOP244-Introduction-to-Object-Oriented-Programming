//OOP244 Workshop 3: Dynamic Memory
//File Weather.cpp
//Date September 28, 2016
//Author Alena Mitrakhovich
//amitrakhovich@myseneca.ca
//115 297 152
//Description
//Implementing the set and display functions

#include <iostream>
#include <cstring>
using namespace std;
#include "Weather.h"

namespace ict {

  void Weather::set(const char* date_description, double high, double low) {
    strcpy(dateTemp_, date_description);
    highTemp_ = high;
    lowTemp_ = low;

    }

  void Weather::display() const {
    cout.width(10);
    cout.fill('_');
    cout.setf(ios::left);
    cout << dateTemp_;
    cout.unsetf(ios::left);

    cout.width(6);
    cout.fill('_');
    cout.setf(ios::fixed);
    cout.precision(1);
    cout << highTemp_;
    cout.unsetf(ios::fixed);

    cout.width(6);
    cout.fill('_');
    cout.setf(ios::fixed);
    cout.precision(1);
    cout << lowTemp_ << endl;
    cout.unsetf(ios::fixed);
  }

}