//Alena Mitrakhovich
//115 297 152
//amitrakhovich@myseneca.ca
//Car.h

#ifndef SICT_CAR_H_
#define SICT_CAR_H_
#include "Vehicle.h"
namespace sict
{
  class Car:public Vehicle {
  private:
    // private members 
    int speed_;
    int maxSpeed_;
  protected:
    // protected members
    void speed(int value);
    int maxSpeed() const;
  public:
    // public members 
    int speed() const;
    Car(int maxSpeed = 100);
  };
}

#endif