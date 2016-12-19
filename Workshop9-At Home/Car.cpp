//Alena Mitrakhovich
//115 297 152
//amitrakhovich@myseneca.ca
//Car.cpp

#include "Car.h"

namespace sict
{

  // protected members 
  void Car::speed(int value) {
    speed_ = value;
    if (value > maxSpeed_) {
      speed_ = maxSpeed_;
    }
    if (value < 0) {
      speed_ = 0;
    }
  }

  int Car::maxSpeed() const {
    return maxSpeed_;
  }

  // public members
  int Car::speed() const {
    return speed_;
  }

  Car::Car(int maxSpeed) {
    maxSpeed_ = maxSpeed;
    speed_ = 0;
  }

  //virtual
  std::ostream& Car::display(std::ostream& ostr) const {
      if (Car::speed() > 0) {
        ostr << ", traveling at the speed of " << Car::speed() << " km/h.";
      }
      else if (Car::speed() == 0) {
        ostr << " and is parked.";
      }

      return ostr;
  }

  //
  std::ostream& operator<<(std::ostream& os, const Car& c){
    c.display(os);
    return os;
  }

}