// Final Project Milestone 1
// File	Date.h
// Version 1.0
// Date	2016/10/29
// Author	Alena Mitrakhovich
// 115 297 152
// amitrakhovich@myseneca.ca
// Description
// Defining Date Class
//
/////////////////////////////////////////////////////////////////

#ifndef ICT_DATE_H__
#define ICT_DATE_H__
// header file includes

#include <iostream>

namespace ict {
  // Error code values go here
#define NO_ERROR 0 //No error - the date is valid
#define CIN_FAILED 1 //istream failed on accepting information
#define YEAR_ERROR 2 //Year value is invalid
#define MON_ERROR 3 //Month value is invalid
#define DAY_ERROR 4 //Day value is invalid

  class Date {
  private:
    // private member variables
    int year_;
    int mon_;
    int day_;
    int readErrorCode_;

    // private member functions and setters
    int value()const;
    void errCode(int errorCode);


  public:
    // constructors
    Date();
    Date(int year, int mon, int day);
    ~Date();

    // operator overloads
    bool operator==(const Date& D)const;
    bool operator!=(const Date& D)const;
    bool operator<(const Date& D)const;
    bool operator>(const Date& D)const;
    bool operator<=(const Date& D)const;
    bool operator>=(const Date& D)const;

    // IO member functions
    std::istream& read(std::istream& istr);
    std::ostream& write(std::ostream& ostr) const;

    // public member functions and getters
    int mdays()const;
    int errCode() const;
    bool bad() const;

  };
  // operator << and >> overloads prototypes for ostream and istream go here
  std::ostream& operator<<(std::ostream& os, const Date& d);
  std::istream& operator>>(std::istream& is, Date& d);
}
#endif