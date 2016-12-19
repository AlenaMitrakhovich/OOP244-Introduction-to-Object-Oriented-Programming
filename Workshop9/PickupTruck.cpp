//Alena Mitrakhovich
//115 297 152
//amitrakhovich@myseneca.ca
//PickupTruck.cpp

#include "PickupTruck.h"
#include <cstring>
namespace sict
{

  // public members
  PickupTruck::PickupTruck() {
    loadAmount_ = 0;
    loadedMaterial_[0] = '\0';
  }

  void PickupTruck::load(const char* loadedMaterial, int loadAmount) {
    loadAmount_ = loadAmount;
    strcpy(loadedMaterial_, loadedMaterial);
  }

  void PickupTruck::unload() {
    loadAmount_ = 0;
  }

  bool PickupTruck::isEmpty() const {
    bool ret = false;
    if (loadAmount_ == 0) {
      ret = true;
    }
    return ret;
  }

  // pure virtual members from base class
  void PickupTruck::accelerate() {
    int value;
    value = Car::speed() + 20;
    Car::speed(value);
  }

  void PickupTruck::brake() {
    int value;
    value = Car::speed() - 5;
    Car::speed(value);
  }

  std::ostream& PickupTruck::display(std::ostream& ostr) const {
    if (isEmpty()) {
      ostr << "This pickup truck is not carrying any load";
    }
    else {
      ostr << "This pickup truck is carrying " << loadAmount_ << " kgs of " << loadedMaterial_;
    }

    if (Car::speed() > 0) {
      ostr << ", traveling at the speed of " << Car::speed() << " km/h.";
    }
    else if (Car::speed() == 0) {
      ostr << " and is parked.";
    }

    return ostr;
  }


}