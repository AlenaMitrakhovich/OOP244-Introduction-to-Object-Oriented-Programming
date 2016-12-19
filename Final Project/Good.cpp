// Final Project Milestone 3 
// Good Tester program
// File	Good.cpp
// Version 1.0
// Date	2016/11/12
// Author	Alena Mitrakhovich
// amitrakhovich@myseneca.ca
// 115 297 152
/////////////////////////////

#include <cstring>
#include <iostream>
#include <iomanip>
#include "wpgeneral.h"
#include "Good.h"
using namespace std;
namespace ict {

  Good::Good() {
    sku_[0] = '\0';
    name_ = nullptr;
    quantity_ = 0;
    price_ = 0;
    qtyNeeded_ = 0;
    taxed_ = 0;
  }

  Good::Good(const char sku[], const char* name, double price, int qtyNeeded, bool taxed) {
    strcpy(sku_, sku);

    name_ = new char[strlen(name) + 1];
    strcpy(name_, name);

    quantity_ = 0;
    price_ = price;
    qtyNeeded_ = qtyNeeded;
    taxed_ = taxed;
  }

  Good::Good(const Good& c) {
    strncpy(sku_, c.sku_, MAX_SKU_LEN + 1);
    quantity_ = c.quantity_;
    price_ = c.price_;
    qtyNeeded_ = c.qtyNeeded_;
    taxed_ = c.taxed_;

    if (c.name_ != nullptr) {
      name_ = new char[strlen(c.name_) + 1];
      strcpy(name_, c.name_);
    }
    else {
      name_ = nullptr;
    }
  }

  Good& Good::operator=(const Good& c) {
    if (this != &c) {
      strncpy(sku_, c.sku_, MAX_SKU_LEN + 1);
      quantity_ = c.quantity_;
      price_ = c.price_;
      qtyNeeded_ = c.qtyNeeded_;
      taxed_ = c.taxed_;
      delete[] name_;
      if (c.name_ != nullptr) {
        name_ = new char[strlen(c.name_) + 1];
        strcpy(name_, c.name_);
      }
      else {
        name_ = nullptr;
      }
    }
    return *this;
  }

  Good::~Good() {
    delete[] name_;
  }

  //setters
  void Good::sku(char sku[]) {
    strncpy(sku_, sku, MAX_SKU_LEN + 1);
  }

  void Good::name(char* name) {
    delete[] name_;
    name_ = new char[strlen(name) + 1];
    strcpy(name_, name);
  }

  void Good::price(double price) {
    price_ = price;
  }

  void Good::taxed(bool taxed) {
    taxed_ = taxed;
  }

  void Good::quantity(int quantity) {
    quantity_ = quantity;
  }

  void Good::qtyNeeded(int qtyNeeded) {
    qtyNeeded_ = qtyNeeded;
  }

  //getters
  const char* Good::sku() const {
    return sku_;
  }

  double Good::price() const {
    return price_;
  }

  const char* Good::name() const {
    return name_;
  }

  bool Good::taxed() const {
    return taxed_;
  }

  int Good::quantity() const {
    return quantity_;
  }

  int Good::qtyNeeded() const {
    return qtyNeeded_;
  }

  double Good::cost() const {
    double ret;
    if (taxed_) {
      ret = price_ + (price_ * TAX);
    }
    else {
      ret = price_;
    }

    return ret;
  }

  //member operator overloads
  bool Good::operator==(const char* sku) const {
    bool ret;
    if (strcmp(sku_, sku) == 0) {
      ret = true;
    }
    else
      ret = false;

    return ret;
  }

  int Good::operator+=(int quantity) {
    quantity_ += quantity;
    return quantity_;
  }

  //non-member operator overload
  double operator+=(double &price, const Good& g) {
    double val;
    val = g.cost() * g.quantity();
    price += val;
    return price;
  }

  //non-member IO operator overloads
  std::ostream& operator<<(std::ostream& os, const Good& g) {
    g.display(os, true);

    return os;
  }

  std::istream& operator>>(std::istream& is, Good& g) {
    g.conInput(is);

    return is;
  }

}