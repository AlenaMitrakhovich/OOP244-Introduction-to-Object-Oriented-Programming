// Final Project
// File	OnShelf.cpp
// Author	Alena Mitrakhovich
// 115 297 152
// amitrakhovich@myseneca.ca

#include "OnShelf.h"
#include <iostream>
#include <iomanip>
namespace ict {

  //constructor
  OnShelf::OnShelf(char recTag) {
    recTag_ = recTag;
  }

  //pure virtual methods of ReadWritable
  std::fstream& OnShelf::store(std::fstream& file, bool addNewLine)const {
    file << recTag_ << ",";
    file << Good::sku() << "," << Good::name() << "," << Good::price() << "," << Good::taxed() << "," << Good::quantity() << "," << Good::qtyNeeded();
    if (addNewLine == true) {
      file << std::endl;
    }
    return file;
  }

  std::fstream& OnShelf::load(std::fstream& file) {
    char sku[MAX_SKU_LEN + 1];
    char name[1000];
    double price;
    bool taxed;
    int quantity;
    int qtyNeeded;

    file.getline(sku, MAX_SKU_LEN + 1, ',');
    file.getline(name, 100, ',');

    file >> price;
    file.ignore(1, ',');
    file >> taxed;
    file.ignore(1, ',');
    file >> quantity;
    file.ignore(1, ',');
    file >> qtyNeeded;
    file.ignore(1, ',');

    Good::sku(sku);
    Good::name(name);
    Good::price(price);
    Good::taxed(taxed);
    Good::quantity(quantity);
    Good::qtyNeeded(qtyNeeded);

    return file;
  }

  std::ostream& OnShelf::display(std::ostream& os, bool linear)const {
    if (err_.Error::isClear() == false) {
      os << err_;
    }
    else if (err_.Error::isClear() && linear == true) {
      os << " " << std::left << std::setw(MAX_SKU_LEN) << Good::sku();
      os << '|';
      os << std::left << std::setw(20) << Good::name();
      os << '|';
      os << std::right << std::setw(7) << std::setprecision(2) << std::fixed << Good::cost();
      os << '|';
      if (Good::taxed()) {
        os << " t " << '|';
      }
      else {
        os << "   " << '|';
      }
      os << std::right << std::setw(4) << Good::quantity();
      os << '|';
      os << std::right << std::setw(4) << Good::qtyNeeded();
      os << '|';
    }
    else if (err_.Error::isClear() && linear == false) {
      if (Good::taxed()) {
        os << "Sku: " << Good::sku() << std::endl;
        os << "Name: " << Good::name() << std::endl;
        os << "Price: " << Good::price() << std::endl;
        os << "Price after tax: " << Good::cost() << std::endl;
        os << "Quantity On Hand: " << Good::quantity() << std::endl;
        os << "Quantity Needed: " << Good::qtyNeeded();
      }
      else {
        os << "upc: " << Good::sku() << std::endl;
        os << "name: " << Good::name() << std::endl;
        os << "price: " << Good::price() << std::endl;
        os << "Price after tax: " << "N/A" << std::endl;
        os << "Quantity on hand: " << Good::quantity() << std::endl;
        os << "Quantity needed: " << Good::qtyNeeded();
      }
    }

    return os;
  }

  std::istream& OnShelf::conInput(std::istream& is) {
    char sku[MAX_SKU_LEN + 1];
    char name[1000];
    double price;
    char tax[2];
    bool taxed;
    bool check;
    int quantity;
    int qtyNeeded;

    char message1[] = "Only (Y)es or (N)o are acceptable";
    char message2[] = "Invalid Price Entry";
    char message3[] = "Invalid Quantity Entry";
    char message4[] = "Invalid Quantity Needed Entry";

    std::cout << "Sku: ";
    is.getline(sku, MAX_SKU_LEN + 1, '\n');

    std::cout << "Name: ";
    is.getline(name, 1000, '\n');

    std::cout << "Price: ";
    is >> price;
    is.ignore(1, '\n');

    if (is.fail()) {
      err_.message(message2);
      is.setstate(std::ios::failbit);
    }
    else {
      std::cout << "Taxed: ";
      is.getline(tax, 2, '\n');
      if (tax[0] == 'Y' || tax[0] == 'y' || tax[0] == 'N' || tax[0] == 'n') {
        check = 1;
        if (tax[0] == 'Y' || tax[0] == 'y') {
          taxed = 1;
        }
        else {
          taxed = 0;
        }

        if (check == 1) {
          std::cout << "Quantity On hand: ";
          is >> quantity;
          is.ignore(1, '\n');
          if (is.fail()) {
            err_.message(message3);
            is.setstate(std::ios::failbit);
          }
          else {
            std::cout << "Quantity Needed: ";
            is >> qtyNeeded;
            if (is.fail()) {
              err_.message(message4);
              is.setstate(std::ios::failbit);
            }
            else {
              Good::sku(sku);
              Good::name(name);
              Good::price(price);
              Good::taxed(taxed);
              Good::quantity(quantity);
              Good::qtyNeeded(qtyNeeded);
              err_.Error::clear();
            }
          }
        }
      }
      else {
        err_.message(message1);
        is.setstate(std::ios::failbit);
      }
    }

    return is;
  }

}