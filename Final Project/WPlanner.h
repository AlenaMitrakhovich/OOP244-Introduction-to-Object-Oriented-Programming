//Alena Mitrakhovich
//115 297 152
//amitrakhovich@myseneca.ca
//WPlanner.h
//OOP244 Fardad Soleimanloo

#ifndef ICT_WPlanner_H__
#define ICT_WPlanner_H__
#include "Good.h"

namespace ict {
  class WPlanner {
    char filename_[256];
    Good* items_[MAX_NO_RECS];
    std::fstream datafile_;
    int noOfItems_;
    int menu();
    void loadRecs();
    void saveRecs();
    void listItems()const;
    int SearchItems(const char* sku)const;
    void updateQty();
    void addItem(bool isCustomMade);
    void deleteItem();
    void getSku(char* sku);
  public:
    //Copy and assignment prevention goes here:
    WPlanner(const WPlanner& og) = delete;
    WPlanner& operator=(const WPlanner og) = delete;

    WPlanner(const char* filename);
    ~WPlanner();
    int run();
  };
}
#endif
