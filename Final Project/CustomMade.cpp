// Final Project
// File	CustomMade.cpp
// Author	Alena Mitrakhovich
// 115 297 152
// amitrakhovich@myseneca.ca

#include "CustomMade.h"

namespace ict {

  CustomMade::CustomMade() : OnShelf('C') {
    ;
  }

  const Date& CustomMade::delivery()const {
    return delivery_;
  }

  void CustomMade::delivery(const Date &value) {
    delivery_ = value;
  }

  std::fstream& CustomMade::store(std::fstream& file, bool addNewLine)const {
    OnShelf::store(file, false);
    file << ",";
    delivery_.write(file);
    if (addNewLine == true) {
      file << '\n';
    }
    return file;
  }

  std::fstream& CustomMade::load(std::fstream& file) {
    OnShelf::load(file);
    delivery_.read(file);
    file.ignore(1);
    return file;
  }


  std::ostream& CustomMade::display(std::ostream& os, bool linear)const {
    OnShelf::display(os, linear);
    if (OnShelf::err_.isClear() && Good::name() != nullptr) {
      if (linear == true) {
        os << delivery_;
      }
      else {
        os << '\n' << "delivery date: " << delivery_;
      }
    }

    return os;
  }


  std::istream& CustomMade::conInput(std::istream& is) {
    Date temp;
    OnShelf::conInput(is);
    if (err_.isClear()) {
      std::cout << "delivery date (YYYY/MM/DD) : ";
      temp.read(is);

      if (temp.errCode() == 1) {
        OnShelf::err_.message("Invalid Date Entry");
        is.setstate(std::ios::failbit);
      }
      else if (temp.errCode() == 2) {
        OnShelf::err_.message("Invalid Year in Date Entry");
        is.setstate(std::ios::failbit);
      }
      else if (temp.errCode() == 3) {
        OnShelf::err_.message("Invalid Month in Date Entry");
        is.setstate(std::ios::failbit);
      }
      else if (temp.errCode() == 4) {
        OnShelf::err_.message("Invalid Day in Date Entry");
        is.setstate(std::ios::failbit);
      }
    }

    delivery_ = temp;

    return is;
  }


}