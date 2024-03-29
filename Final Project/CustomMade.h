// Final Project
// File	CustomMade.h
// Author	Alena Mitrakhovich
// 115 297 152
// amitrakhovich@myseneca.ca

#ifndef ICT_CUSTOMMADE_H__
#define ICT_CUSTOMMADE_H__
#include "OnShelf.h"
#include "Date.h"
#include "Error.h"
namespace ict {
  class CustomMade :public OnShelf {
  private:
    Date delivery_;
  public:
    CustomMade();
    const Date& delivery()const;
    void delivery(const Date &value);
    //virtual
    std::fstream& store(std::fstream& file, bool addNewLine = true)const;
    std::fstream& load(std::fstream& file);
    std::ostream& display(std::ostream& os, bool linear)const;
    std::istream& conInput(std::istream& is);
  };
}


#endif