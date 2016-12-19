//Alena Mitrakhovich
//115 297 152
//amitrakhovich@myseneca.ca
//Driver.cpp

#include "Driver.h"
#include <cstring>
#include <iostream>


namespace sict
{
  Driver::Driver(const char* name, Car& theCar): car_(theCar){
    strcpy(name_, name);
  }

  void Driver::drive() {
    car_.accelerate();
    car_.brake();
    showStatus();
  }

  void Driver::stop() {
    for ( ; car_.speed() > 0; ) {
      car_.brake();  
    }
    showStatus();
  }

  void Driver::showStatus() {
    std::cout << name_ << " is driving this car." << std::endl;
    std::cout << car_ << std::endl;
  }
  
}