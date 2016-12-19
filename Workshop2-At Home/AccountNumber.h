// OOP244 Workshop 2: Compound types and privacy
// File	AccountNumber.h
// Version 1.0
// Date	September 25, 2016
// Author	Alena Mitrakhovich
// 115 297 152
// amitrakhovich@myseneca.ca
// Description
// This header file defines the needed values and
// declares a class with private member variables
// and public and private member functions
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// 
///////////////////////////////////////////////////////////

#ifndef SICT_ACCOUNTNUMBER_H_
#define SICT_ACCOUNTNUMBER_H_

namespace sict {

#define MAX_NAME_LENGTH   40
#define  MIN_BANKCODE    100
#define  MAX_BANKCODE   999
#define  MIN_BRANCHCODE    1
#define  MAX_BRANCHCODE   220
#define  MIN_ACCNO    10000
#define  MAX_ACCNO    99999

  class AccountNumber {
  private:
    char _name[MAX_NAME_LENGTH + 1];
    int _bankCode;
    int _branchCode;
    int _accountNumber;
    bool _validAccNumber;
  public:
    void name(const char name[]);
    void accountNumber(int bankCode, int branchCode, int accountNumber);
    void display(bool display_name = true, bool display_number = true) const;
    bool isValid() const;
  private:
    void displayName() const;
    void displayNumber() const;
  };

}

#endif
