#include <iostream>
using namespace std;

int gcd(int m, int n)
{
  int t = 1;
  while (t != 0)
  {
    t = m % n;
    m = n;
    n = t;
  }
  return m;
}
int main(void)
{
  int a, b;
  while (cin >> a)
  {
    if (a == EOF)
      return 0;
    cin >> b;
    printf("%d\n", gcd(a, b));
  }
  return 0;
}
