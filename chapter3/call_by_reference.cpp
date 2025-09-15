#include <iostream>
using namespace std;

int modifyint& x, int& y)
{
  x = x * 2;
  y = y * 2;
}

int main()
{
  int a=2, b=3;
  modify(a,b);
  cout <<"a="<<a<<endl;
  cout <<"b="<<b<<endl;
  return 0;
}
