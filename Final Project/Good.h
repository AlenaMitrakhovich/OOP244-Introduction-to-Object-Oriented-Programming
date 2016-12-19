// Date	2016/11/12
// Author	Alena Mitrakhovich
// amitrakhovich@myseneca.ca
// 115 297 152
/////////////////////////////

#ifndef ICT_GOOD_H__
#define ICT_GOOD_H__
#include "ReadWritable.h"
#include "wpgeneral.h"

namespace ict {

  class Good : public ReadWritable {
    char sku_[MAX_SKU_LEN + 1];
    char* name_;
    double price_;
    bool taxed_;
    int quantity_;
    int qtyNeeded_;
  public:
    Good();
    Good(const char sku[], const char* name, double price, int qtyNeeded, bool taxed = "true");
    Good(const Good& c);
    Good& operator=(const Good& c);
    virtual ~Good();
    //setters
    void sku(char sku[]);
    void name(char* name);
    void quantity(int quantity);
    void qtyNeeded(int qtyNeeded);
    void taxed(bool taxed);
    void price(double price);
    //getters
    const char* sku() const;
    double price() const;
    const char* name() const;
    bool taxed() const;
    int quantity() const;
    int qtyNeeded() const;
    double cost() const;
    //overloads
    bool operator==(const char* sku) const;
    int operator+=(int quantity);
    //write and read
    virtual std::ostream& display(std::ostream& os, bool linear = "true")const = 0;
    virtual std::istream& conInput(std::istream& is) = 0;
  };

  //non-member overload
  double operator+=(double &price, const Good& g);

  //non-member I0 overload
  std::ostream& operator<<(std::ostream& os, const Good& g);
  std::istream& operator>>(std::istream& is, Good& g);
}


#endif