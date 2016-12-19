//Alena Mitrakhovich
//115 297 152
//amitrakhovich@myseneca.ca
//WPlanner.cpp
//OOP244 Fardad Soleimanloo

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "WPlanner.h"
#include "Good.h"
#include "OnShelf.h"
#include "CustomMade.h"

using namespace std;

namespace ict {

  WPlanner::WPlanner(const char* filename) {
    strcpy(filename_, filename);

    for (int x = 0; x < MAX_NO_RECS; x++) {
      items_[x] = nullptr;
    }

    noOfItems_ = 0;

    loadRecs();
  }

  WPlanner::~WPlanner() {
    for (int x = 0; x < MAX_NO_RECS; x++) {
      delete items_[x];
    }
  }

  void WPlanner::saveRecs() {

    datafile_.open(filename_, ios::out);

    for (int x = 0; x < noOfItems_; x++) {
      items_[x]->store(datafile_);
    }

    datafile_.close();

  }

  void WPlanner::loadRecs() {
    int readIndex = 0;
    char id;

    datafile_.open(filename_, ios::in);
    if (datafile_.fail()) {
      datafile_.clear();
      datafile_.close();
      datafile_.open(filename_, ios::out);
      datafile_.close();
    }
    else {
      while (!datafile_.fail()) {
        delete items_[readIndex];
        id = 0;
        datafile_ >> id;

        if (id == 'C') {
          items_[readIndex] = new CustomMade();
          datafile_.ignore();
          items_[readIndex]->load(datafile_);
          readIndex++;
        }
        else if (id == 'O') {
          items_[readIndex] = new OnShelf();
          datafile_.ignore();
          items_[readIndex]->load(datafile_);
          readIndex++;
        }
      }
      noOfItems_ = readIndex;
      datafile_.close();
    }
  }

  void WPlanner::getSku(char* sku) {
    cout << "Please enter the SKU: ";
    cin.getline(sku, MAX_SKU_LEN + 1, '\n');
    cout << endl;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(2000, '\n');
    }

  }

  void WPlanner::deleteItem() {
    cout << "Not implemented!" << endl << endl;

    /*bool check = false;
    int index;
    char choice;
    
    char sku[MAX_SKU_LEN];
    getSku(sku);

    for (int x = 0; x < noOfItems_; x++) {
      if (*items_[x] == sku) {
        check = true;
        index = x;
        //get out of loop
        x += noOfItems_ + 10;
      }
    }

    if (!check) {
      cout << "Item Not found!" << endl << endl;
    }

    if (check) {
      cout << "The following Item will be deleted:" << endl;
      items_[index]->display(std::cout, false);
      cout << endl << endl;
      cout << "Type (Y) to confirm or (N) to abort: ";
      cin >> choice;
      if (choice == 89 || choice == 121) {
        cout << endl;
        delete items_[index];
        for (int y = index+1; y < noOfItems_; y++) {
          //everything after index moved to their current index-1
          items_[y] = items_[y - 1];
        }
        noOfItems_ -= 1;

        //clear file
        datafile_.open(filename_, ios::in);
        if (!datafile_.fail()) {
          datafile_.clear();
          datafile_.close();
          datafile_.open(filename_, ios::out);
          datafile_.close();
        }

        datafile_.open(filename_, ios::out);
        for (int x = 0; x < noOfItems_; x++) {
          items_[x]->store(datafile_);
        }
        datafile_.close();


        cout << "Item deleted!" << endl << endl;
      }
      else {
        cout << "Aborted!" << endl << endl;
      }
    }

  */
  }

  void WPlanner::updateQty() {
    char sku[MAX_SKU_LEN];
    bool check = false;
    int index;
    int qty;
    int qtyReq;
    getSku(sku);

    for (int x = 0; x < noOfItems_; x++) {
      if (*items_[x] == sku) {
        check = true;
        index = x;
        x += noOfItems_ + 10;
      }
    }

    if (!check) {
      cout << endl << "Not found!" << endl;
    }

    if (check) {
      items_[index]->display(std::cout, false) << endl;
      cout << endl << "Please enter the number of purchased goods: ";
      cin >> qty;
      cout << endl;
      if (cin.fail()) {
        cout << "Invalid Quantity value!" << endl;
      }
      else {
        qtyReq = items_[index]->qtyNeeded() - items_[index]->quantity();
        if (qty <= qtyReq) {
          qty = qty;
        }
        else {
          cout << "Too many purchased, only " << qtyReq << " needed, please return the extra " << qty - qtyReq << endl;
          qty = qtyReq;
        }
      }
      *items_[index] += qty;
    
      saveRecs();
      cout << "Updated!" << endl << endl;
    }

    cin.clear();
    cin.ignore(2000, '\n');
  }

  void WPlanner::listItems()const {
    double totCost = 0.0;

    cout << " Row | SKU | Good Name          | Cost  |Tax| QTY|Need| Delivery" << endl
      << "-----|-----|--------------------|-------|---|----|----|----------" << endl;

    for (int x = 0; x < noOfItems_; x++) {
      cout << right << setw(4) << setfill(' ') << x + 1 << " " << "|" << *items_[x] << endl;
      totCost += items_[x]->cost() * items_[x]->quantity();
    }


    cout << "-----+-----+--------------------+-------+---+----+----+----------" << endl;

    cout << "Total cost of the Wedding: " << "$" << setprecision(2) << totCost << endl << endl;

  }

  int WPlanner::SearchItems(const char* sku)const {
    bool check = false;
    int ret = -1;

    for (int x = 0; x < noOfItems_ && check == false; x++) {
      if (*items_[x] == sku) {
        ret = x;
        check = true;
      }
    }

    return ret;
  }

  void WPlanner::addItem(bool isCustomMade) {

    if (isCustomMade) {
      items_[noOfItems_] = new CustomMade();
      items_[noOfItems_]->conInput(std::cin);
      if (cin.fail()) {
        cin.ignore(1000, '\n');
        items_[noOfItems_]->display(std::cout, false);
        cout << endl;
        delete[] items_[noOfItems_];
        items_[noOfItems_] = nullptr;
      }
    }

    else if (!isCustomMade) {
      items_[noOfItems_] = new OnShelf();
      items_[noOfItems_]->conInput(std::cin);
      if (cin.fail()) {
        cin.ignore(1000, '\n');
        items_[noOfItems_]->display(std::cout, false);
        cout << endl;
        delete[] items_[noOfItems_];
        items_[noOfItems_] = nullptr;
      }
    }

    if (!cin.fail()) {
      noOfItems_ += 1;
      saveRecs();
      cout << endl << "Good added" << endl << endl;
    }

  }

  int WPlanner::menu() {
    int selection = -1;

    cout << "Wedding Planner Management Program" << endl;
    cout << "1 - List goods" << endl;
    cout << "2 - Add On Shelf Good" << endl;
    cout << "3 - Add Custom-Made Good" << endl;
    cout << "4 - Update Good quantity" << endl;
    cout << "5 - Delete" << endl;
    cout << "0 - Exit program" << endl;
    cout << "> ";
   
    cin >> selection;
    cout << endl;

    if (selection < 0 || selection > 5) {
      selection = -1;
    }
    else {
      selection = selection;
    }

    cin.clear();
    cin.ignore(2000, '\n');

    return selection;
  }

  int WPlanner::run() {

    bool done = false;
    while (!done) {
      
      int selection = menu();
      switch (selection) {
      case 1:
        listItems();
        break;
      case 2:
        addItem(false);
        break;
      case 3:
        addItem(true);
        break;
      case 4:
        updateQty();
        break;
      case 5:
        deleteItem();
        break;
      case 0:
        done = true;
        cout << "Goodbye!!" << endl << endl;
        break;
      case -1:
        cout << "===Invalid Selection, try again.===" << endl << endl;
        break;
      }
    }
    return 0;
  } // WPlanner::run() end
}


/* outputs
Wedding Planner Management Program
1 - List goods
2 - Add On Shelf Good
3 - Add Custom-Made Good
4 - Update Good quantity
5 - Delete
0 - Exit program
>
Not found!
Please enter the number of purchased goods:
Too many purchased, only 5 needed, please return the extra 15.
Updated!
Not implemented!
*/