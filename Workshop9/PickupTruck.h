//Alena Mitrakhovich
//115 297 152
//amitrakhovich@myseneca.ca
//PickupTruck.h

#ifndef SICT_TRUCK_H_
#define SICT_TRUCK_H_
#include "Car.h"
#include <iostream>
namespace sict
{
  // complete the declaration of the class
  class PickupTruck:public Car{
  private:
    // private members 
    int loadAmount_;
    char loadedMaterial_[31];
  public:
    // public members
    PickupTruck();
    void load(const char* loadedMaterial, int loadAmount);
    void unload();
    bool isEmpty() const;
    // pure virtual members from base class
    void accelerate();
    void brake();
    std::ostream& display(std::ostream& ostr) const;
  };
}
#endif