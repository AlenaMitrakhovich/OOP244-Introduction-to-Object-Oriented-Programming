//Alena Mitrakhovich
//115 297 152
//amitrakhovich@myseneca.ca
//Vehicle.h

#ifndef SICT_VEHICLE_
#define SICT_VEHICLE_
#include <iostream>
namespace sict
{
  class Vehicle
  {
  public:
    // public members
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual std::ostream& display(std::ostream& ostr) const = 0;
  };
}
#endif