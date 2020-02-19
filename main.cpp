// main.cpp

#include "str.h"

int main()
{
  cout << "TEST PROGRAM !!" << endl;

  str s1("Hello");

  cout << "s1 = ";
  s1.print();

  str s3("!!!");

  cout << "s3 = ";
  s3.print();

  cout << "After operator overloading" << endl;

  str s2 = s1;
  cout << "Using of overloading << " << endl;
  cout << s2 << endl;

  s2 = s2 + s3;
  cout << s2 << endl;

  str s4;

  cin >> s4;
  cout << s4;

  return 0;
}
