// str.cpp

#include "str.h"
#include <cstring>

using namespace std;

str::str()
{
  _buf = nullptr;
  _n = 0;
}

str::str(char ch)
{
   _n = 1;
  _buf = new char[_n];
  _buf[0] = ch;
}

str::str(const char* c_str)
{
  _n = strlen(c_str);
  _buf = new char[_n];
  for (int i = 0; i < _n; ++i)
    _buf[i] = c_str[i];
}
str::str(const str &s)
{
  _n = s._n;
  _buf = new char[_n];
  for (int i = 0; i < _n; ++i)
    _buf[i] = s._buf[i];
}

str::~str()
{
  if (_buf)
    delete [] _buf;
  _n = 0;
  _buf = nullptr;
}

void str::print()
{
  for (int i = 0; i < _n; ++i)
    cout << _buf[i];
  cout << endl;
}

void str::clear()
{
  if (_buf)
    delete [] _buf;

  _buf = nullptr;
  _n = 0;
}

void str::append(const str & s)
{
  char *p = new char[_n + s._n];

  int i;

  for (i = 0; i < _n; ++i)
    p[i] = _buf[i];

  for (int j = 0; j < s._n; ++i,++j)
    p[i] = s._buf[j];

  if (_buf)
    delete [] _buf;

  _buf = p;
  _n = _n + s._n;
}

void swap(str& x, str& y)
{
  char *tmp;
  int ntmp;

  tmp = x._buf;
  x._buf = y._buf;
  y._buf = tmp;

  ntmp = x._n;
  x._n = y._n;
  y._n = ntmp;

}


str & str::operator=(str &c){
  char *temp = new char[c._n];
  for (int i=0; i<c._n; i++){
    temp[i] = c._buf[i];
  }

  delete _buf;

  _n = c._n;

  _buf = new char[_n];
  strcpy(_buf, temp);

  delete temp;
  return *this;
}


str & str::operator+(str &s1){
  char *p = new char[_n + s1._n];

  int i;

  for (i = 0; i < _n; ++i)
    p[i] = _buf[i];

  for (int j = 0; j < s1._n; ++i,++j)
    p[i] = s1._buf[j];

  if (_buf)
    delete [] _buf;

  _buf = p;
  _n = _n + s1._n;

  return *this;
}

ostream & operator<<(ostream &out, str &s){

  out << "String is " << s._buf << endl;

  return out;
}

istream & operator>>(istream &in, str &s){
  char tmp_buf[200];

  cout << "string: ";
  in >> tmp_buf;

  str s5(tmp_buf);
  s = s5;

  return in;
}
