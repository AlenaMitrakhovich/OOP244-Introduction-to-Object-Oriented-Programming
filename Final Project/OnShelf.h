// Final Project
// File	OnShelf.h
// Author	Alena Mitrakhovich
// 115 297 152
// amitrakhovich@myseneca.ca

#ifndef ICT_ONSHELF_H__
#define ICT_ONSHELF_H__
#include "Good.h"
#include "Error.h"
namespace ict {
  class OnShelf :public Good {
  private:
    char recTag_;
  protected:
    Error err_;
  public:
    //constructor
    OnShelf(char recTag = 'O');
    //pure virtual methods of ReadWritable
    std::fstream& store(std::fstream& file, bool addNewLine = true)const;
    std::fstream& load(std::fstream& file);
    std::ostream& display(std::ostream& os, bool linear)const;
    std::istream& conInput(std::istream& is);
  };
}
#endif