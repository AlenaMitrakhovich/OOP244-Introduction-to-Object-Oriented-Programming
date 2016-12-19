// OOP244 Workshop 5: Classes with resources 
// File: Contact.cpp
// Version: 1.0
// Date: October 16, 2016
// Author: Alena Mitrakhovich
// amitrakhovich@myseneca.ca
// 115 297 152
/////////////////////////////////////////////

#include "Contact.h"
#include "PhoneNumber.h"
#include <cstring>
#include <iostream>     
#include <iomanip>
using namespace std;

namespace ict {

  void Contact::read() {
    cout << "Contact Name: ";
    cin.getline(name_, 41, '\n');
    cout << "Please enter " << noPN_ << " phone numbers: " << endl;
    for (int i = 0; i < noPN_; i++) {
      cout << i + 1 << ": ";
      phoneNumber_[i].read();
    }
  }

  bool Contact::isEmpty()const {
    return phoneNumber_ == nullptr;
  }

  void Contact::setEmpty() {
    name_[0] = 0;
    noPN_ = 0;
    phoneNumber_ = nullptr;
  }

  Contact::Contact() {
    setEmpty();
  }

  Contact::Contact(const char* name, int noPN) {
    phoneNumber_ = nullptr;
    phoneNumber_ = new PhoneNumber[noPN];
    noPN_ = noPN;
    //the dynamic way of doing it - stores the long name:
    //name_ = new char[strlen(name) + 1];
    //strcpy(name_, name);
    name_[40] = '\0';
    strncpy(name_, name, 40);
  }

  Contact::~Contact() {
    delete[] phoneNumber_;
    //when dynamic is used:
    //delete[] name_;
  }

  void Contact::display() const {
    int x;
    cout << name_ << endl;
    for (x = 0; x < noPN_; x++) {
      phoneNumber_[x].PhoneNumber::display();
      //phoneNumber_[x].display(true);  
    }
    cout.fill('-');
    cout.width(40);
    cout << '-' << endl;
  }

  Contact::Contact(const Contact& c) {
    strcpy(name_, c.name_);
    noPN_ = c.noPN_;
    if (c.phoneNumber_ != nullptr) {
      phoneNumber_ = new PhoneNumber[noPN_];
      for (int i = 0; i < noPN_; i++) {
        phoneNumber_[i] = c.phoneNumber_[i];
      }
    }
    else {
      phoneNumber_ = nullptr;
    }
  }

  Contact& Contact::operator=(const Contact& c) {
    if (this != &c) {
      strcpy(name_, c.name_);
      noPN_ = c.noPN_;
      delete[] phoneNumber_;
      if (c.phoneNumber_ != nullptr) {
        phoneNumber_ = new PhoneNumber[noPN_];
        for (int x = 0; x < noPN_; x++) {
          phoneNumber_[x] = c.phoneNumber_[x];
        }
      }
      else {
        phoneNumber_ = nullptr;
      }
    }
    return *this;
  }
}