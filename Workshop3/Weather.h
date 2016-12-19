#pragma once
//OOP244 Workshop 3: Dynamic Memory
//File Weather.h
//Date September 28, 2016
//Author Alena Mitrakhovich
//amitrakhovich@myseneca.ca
//115 297 152
//Description
//Creating the class Weather with private member variables
//and public member functions


#ifndef ICT_WEATHER_H__
#define ICT_WEATHER_H__

namespace ict {
  
  class Weather {
    char dateTemp_[7] = {0};
    double highTemp_ = 0;
    double lowTemp_ = 0;
    public:
    void set(const char* dateTemp, double highTemp, double lowTemp);
    void display() const;
  };

}

#endif