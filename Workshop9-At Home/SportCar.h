//Alena Mitrakhovich
//115 297 152
//amitrakhovich@myseneca.ca
//SportCar.h

#ifndef SICT_SPORTCAR_H_
#define SICT_SPORTCAR_H_
#include "Car.h"
#include <iostream>
namespace sict
{

  class SportCar :public Car {
  private:
    // private members
    int noOfPassengers_;
  public:
    // public members
    SportCar();
    SportCar(int maxSpeed, int noOfPassengers);
    // pure virtual members from base class
    void accelerate();
    void brake();
    std::ostream& display(std::ostream& ostr) const;
  };
}
#endif