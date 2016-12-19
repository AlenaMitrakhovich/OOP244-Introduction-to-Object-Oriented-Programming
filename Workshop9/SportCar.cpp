//Alena Mitrakhovich
//115 297 152
//amitrakhovich@myseneca.ca
//SportCar.cpp

#include "SportCar.h"


namespace sict
{
  // public members
  SportCar::SportCar() {
    noOfPassengers_ = 1;
  }

  SportCar::SportCar(int maxSpeed, int noOfPassengers):Car(maxSpeed) {
    noOfPassengers_ = noOfPassengers;
  }

  // pure virtual members from base class
  void SportCar::accelerate() {
    int value;
    value = Car::speed() + 40;
    Car::speed(value);
  }

  void SportCar::brake() {
    int value;
    value = Car::speed() - 10;
    Car::speed(value);
  }

  std::ostream& SportCar::display(std::ostream& ostr) const {
    if (Car::speed() > 0) {
      ostr << "This sport car is carrying " << noOfPassengers_ << " passengers and is traveling at a speed of " << Car::speed() << " km/h.";
    }
    else if (Car::speed() == 0) {
      ostr << "This sport car is carrying " << noOfPassengers_ << " passengers and is parked.";
    }

    return ostr;
  }


}