// OOP244 Workshop 2: Compound types and privacy
// File	  AccountNumber.cpp
// Version 1.0
// Date	September 20, 2016
// Author	Alena Mitrakhovich
// Description
// This implementation file defines the functions
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// 
///////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
using namespace std;
#include "AccountNumber.h"

namespace sict {
  
  void AccountNumber::name(const char name[]) {
    strcpy(_name, name);
  }

  void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber) {
    _bankCode = bankCode;
    _branchCode = branchCode;
    _accountNumber = accountNumber;

    if (bankCode >= MIN_BANKCODE && bankCode <= MAX_BANKCODE){
      if(branchCode >= MIN_BRANCHCODE && branchCode <= MAX_BRANCHCODE)
        if(accountNumber >= MIN_ACCNO && accountNumber <= MAX_ACCNO)
      _validAccNumber = true;
    }
    else {
      _validAccNumber = false;
    }
  }

  bool AccountNumber::isValid() const {
    return _validAccNumber;
  }

  void AccountNumber::display(bool display_name, bool display_number) {

    if (display_name == true && display_number == true) {
      if (true == isValid()) {
        cout << "Name: " << _name << ", Account number: " << _bankCode << "-" << _branchCode << "-" << _accountNumber << endl;
      }
      else {
        cout << _name << " does not have a valid account number." << endl;
      }
    }

    if (display_name == false && display_number == true) {
      displayNumber();
    }

    if (display_name == true && display_number == false) {
      displayName();
    }

    if (display_name == false && display_number == false) {
      ;
    }

  }

  void AccountNumber::displayName() const {
      cout << "Name: " << _name;
  }

  void AccountNumber::displayNumber() const {
      cout << "Account number: " << _bankCode << "-" << _branchCode << "-" << _accountNumber;
  }

}