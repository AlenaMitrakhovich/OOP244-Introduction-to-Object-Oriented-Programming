#pragma once
// OOP244 Workshop 4: Constructors 
// File: Enrollment.h
// Version: 1.0
// Date: October 7, 2016
// Author: Alena Mitrakhovich
// amitrakhovich@myseneca.ca
// 115 297 152
// Description:
// Specifying enrollment class
/////////////////////////////////////////////

#ifndef ICT_ENROLLMENT_H__
#define ICT_ENROLLMENT_H__


namespace ict {

  class Enrollment {
  private:
    char name_[31];
    char code_[11];
    int year_;
    int semester_;
    int slot_;
    bool enrolled_;
  public:
    Enrollment();
    Enrollment(const char* name, const char* code, int year, int semester, int time);
    ~Enrollment();
    bool isEnrolled() const;
    bool isValid()const;
    void setEmpty();
    void display(bool nameOnly = false) const;
    void set(const char* name, const char* code, int year, int semester, int time, bool enrolled = false);
    bool hasConflict(const Enrollment &other) const;
    void withdraw();
    int enrol(const Enrollment* enrollments, int size);
  };


}

#endif