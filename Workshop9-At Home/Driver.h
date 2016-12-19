//Alena Mitrakhovich
//115 297 152
//amitrakhovich@myseneca.ca
//Driver.h

#ifndef SICT_DRIVER_H_
#define SICT_DRIVER_H_

#include "Car.h"

namespace sict
{
  class Driver {
  private:
    // private members
    char name_[31];
    Car& car_;
  public:
    // public members
    Driver(const char* name, Car& theCar);
    void drive();
    void stop();
    void showStatus();
  };
}
#endif