// OOP244 Workshop 3: Dynamic Memory
// File	w3_at_home.cpp
// Version 1.0
// Date	October 2, 2016
// Author Alena Mitrakhovich
// amitrakhovich@myseneca.ca
// 115 297 152
// Description
// This file is used to demonstrate dynamic memory in 
// C++ and to process an array of objects of compound 
// type where the user specifies the number of 
// elements in the array at run-time.
/////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "Weather.h"
using namespace std;
using namespace ict;

int main() {
  int i; //loop counter
  int n; //the count of days worth of weather
  Weather* weather = nullptr;

  cout << "Weather Data" << endl
    << "=====================" << endl
    << "Days of Weather: ";
  cin >> n;
  cin.ignore();

  weather = new Weather[n];

  for (i = 0; i < n; i++) {
    char date_description[7];
    double high;
    double low;

    cout << "Enter date: ";
    cin >> date_description;
    cout << "Enter high: ";
    cin >> high;
    cout << "Enter low : ";
    cin >> low;

    weather[i].set(date_description, high, low);

  }
  cout << endl
    << "Weather report:" << endl
    << "Date        high  low" << endl
    << "======================" << endl;

  for (i = 0; i < n; i++) {
    weather[i].display();
  }

  char query[7];
  cout << endl << "Enter the date you are looking for: ";
  cin.getline(query, 7, '\n');
  cin >> query;

  double low = findLow(query, weather, n);
  cout.setf(ios::fixed);
  cout.precision(1);
  cout << "Low temperature: " << low << endl;
  cout.unsetf(ios::fixed);

  delete[] weather;
  weather = nullptr;

  return 0;
}
