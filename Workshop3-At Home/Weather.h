//OOP244 Workshop 3: Dynamic Memory
//File Weather.h
//Date October 2, 2016
//Author Alena Mitrakhovich
//amitrakhovich@myseneca.ca
//115 297 152
//Description
//Creating the class Weather with private member variables
//and public member functions
//Global function declaration 


#ifndef ICT_WEATHER_H__
#define ICT_WEATHER_H__

namespace ict {

  class Weather {
  public:
    char dateTemp_[7];
    double highTemp_;
    double lowTemp_;
  public:
    void set(const char* dateTemp, double highTemp, double lowTemp);
    void display() const;
    const char* date() const;
    double low() const;
  };

  double findLow(const char* date, const Weather* data, int dataSize);

}

#endif