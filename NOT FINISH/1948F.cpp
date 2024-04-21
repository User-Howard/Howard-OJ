#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int rec(long long a, long long m) {
	return modpow(a, m-2, m);
}
int main() {
    cout << rec(2048, 998244353);
    return 0;
}