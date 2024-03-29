//Alena Mitrakhovich
//115 297 152
//String.h
//Workshop 10


#ifndef ICT_STRING_H_
#define ICT_STRING_H_

#include <iostream>

const int ExpansionSize = 500;

namespace ict
{
  class String
  {
    char* m_data;
    int m_memSize;
    int m_len;
    void deallocate();
    void allocate(int size);
    void init(const char* str, int memSize);
  public:
    void resize(int newsize);

    // special member functions
    String();
    String(const char* str, int memsize = 500);
    String(const String& str);
    String& operator=(const String& str);
    virtual ~String();

    // accessors
    int getLength() const;
    int getMemSize() const;

    // cast operators
    operator const char*() const;
    operator int() const;

    // operators
    String& operator++();
    String  operator++(int);
    String& operator+=(const char* str);
    String& operator+=(String& s);
    String  operator+ (const String& str) const;
    char&   operator[](int index);

    // IO
    std::istream& read(std::istream& = std::cin);
  };

  std::ostream& operator<<(std::ostream&, const String&);
  std::istream& operator>>(std::istream&, String&);
}

#endif