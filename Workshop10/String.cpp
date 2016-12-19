//Alena Mitrakhovich
//115 297 152
//String.cpp
//Workshop 10


#include <cstring>
#include <iostream>
#include "String.h"

using namespace std;

namespace ict
{

  //PRIVATE
  void String::deallocate() {
    delete[] m_data;
    m_data = nullptr;
    m_memSize = 0;
  }


  void String::allocate(int size) {
    delete[] m_data;
    m_data = new char[size];
    m_memSize = size;
  }

  void String::init(const char* str, int memSize) {
    m_data = nullptr;
    m_len = strlen(str);
    if (memSize < m_len + 1) {
      memSize = m_len + 1;
    }
    allocate(memSize);
    strcpy(m_data, str);
    
  }

  //PUBLIC
  void String::resize(int newsize) {
    char* temp = new char[newsize];
    int i = 0;
    if (m_data != nullptr) {
      for (; i < newsize - 1 && i < m_len; i++) {
        temp[i] = m_data[i];
      }
      deallocate();
    }
    m_memSize = newsize;
    temp[i] = 0;
    m_data = temp;

  }

  // special member functions
  String::String() {
    m_data = nullptr;
    m_memSize = 0;
    m_len = 0;
  }


  String::String(const char* str, int memsize) {
    init(str, memsize);
  }

  String::String(const String& str) {
    init(str.m_data, str.m_memSize);
  }

  String& String::operator=(const String& str) {
    if (this != &str) {
      deallocate();
      init(str.m_data, str.m_memSize);
    }
    return *this;
  }

  String::~String() {
    delete[] m_data;
  }

  // accessors
  int String::getLength() const {
    return m_len;
  }

  int String::getMemSize() const {
    return m_memSize;
  }

  // cast operators
  String::operator const char*() const {

    //static_cast<const char*>(m_data);
    //const char* m_data(m_data);
    return m_data;
  }

  String::operator int() const {
    return m_len;
  }

  // operators
  String& String::operator++() {
    if (m_memSize - m_len > 1) {
      int i = m_len;
      for (; i >= 0; i--) {
        m_data[i + 1] = m_data[i];
      }
    }
    else {
      char* temp = new char[++m_memSize];
      strcpy(temp + 1, m_data);
      delete[] m_data;
      m_data = temp;
    }
    ++m_len;
    *m_data = ' ';
    return *this;
  }

  String String::operator++(int) {
    String temp = *this;
    operator+=(" ");
    return temp;
  }

  String& String::operator+=(const char* str) {
    int newLength = m_len + strlen(str);
    if (newLength + 1 > m_memSize) {
      resize(newLength + 1);
    }
    strcat(m_data, str);
    m_len = newLength;
    return *this;
  }


  String& String::operator+=(String& s) {
    operator+=(s.m_data);
    return *this;
  }

  String  String::operator+ (const String& str) const {
    String temp(m_data);
    temp += str;
    return temp;
  }

  char& String::operator[](int index) {
    if (index > m_len) {
      resize(index + ExpansionSize);
      return m_data[index + ExpansionSize];
    }
    else
      return m_data[index];
  }

  // IO
  std::istream& String::read(std::istream& is) {
    int i;
    char temp;
    for (i = 0; temp != '\n'; i++) {
      is >> m_data[i] >> temp;
      if (i == m_memSize) {
        resize(m_memSize + ExpansionSize);
      }
      m_data[i] = temp;
    }
    m_data[i] = 0;
    return is;
  }

  //non-member
  std::ostream& operator<<(std::ostream& os, const String& s) {
    if (s.operator const char*() != nullptr) {
      os << s.operator const char*();
    }
    return os;
  }

  std::istream& operator>>(std::istream& is, String& s) {
    s.read(is);
    return is;
  }


}