//OOP244 Workshop 3: Dynamic Memory
//File Weather.cpp
//Date October 2, 2016
//Author Alena Mitrakhovich
//amitrakhovich@myseneca.ca
//115 297 152
//Description
//Implementing the set, display, date, and low functions member functions
//Implementing the findLow global function

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

  double findLow(const char* date, const Weather* data, int dataSize) {
    int count;
    int check = 1;
    int objDate = (dataSize + 10);
    double dayLow;

    for (count = 0; count <= dataSize; count ++) {
      check = strcmp(date, (data[count].date()));
      if (check == 0) {
        objDate = count;
        count = dataSize + 1;
      }
    }

    if (objDate != (dataSize + 10)) {
      dayLow = data[objDate].low();
    }
    else {
      dayLow = 0.0;
    }

    return dayLow;

  }

  const char* Weather::date() const {
    return dateTemp_;
  }

  double Weather::low() const {
    return lowTemp_;
  }

}