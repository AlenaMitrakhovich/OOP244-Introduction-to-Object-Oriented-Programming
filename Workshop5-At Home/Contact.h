#pragma once
// OOP244 Workshop 5: Classes with resources 
// File: Contact.h
// Version: 1.0
// Date: October 16, 2016
// Author: Alena Mitrakhovich
// amitrakhovich@myseneca.ca
// 115 297 152
/////////////////////////////////////////////

#ifndef ICT_CONTACT_H_
#define ICT_CONTACT_H_
#include "PhoneNumber.h"

namespace ict {
  class Contact : public PhoneNumber {
    char name_[41];
    //dynamic way of doing it, stores entire long name:
    //char* name_;
    PhoneNumber* phoneNumber_;
    int noPN_;
    void setEmpty();

  public:
    Contact();
    Contact(const char* name, int noPN);
    Contact(const Contact& c);
    Contact& operator=(const Contact& c);
    ~Contact();
    void display() const;
    void read();
    bool isEmpty()const;
  };

}
#endif
