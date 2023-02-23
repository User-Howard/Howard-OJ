#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

uint64_t mul(uint64_t a, uint64_t b, uint64_t mod) { 
	uint64_t ret = 0; 
	for (a = a >= mod ? a%mod : a, b = b >= mod ? b%mod : b; b != 0; b>>=1, a <<= 1, a = a >= mod ? a - mod : a) { 
		if (b&1) {
			ret += a;
			if (ret >= mod) 
				ret -= mod;
		} 
	} 
	return ret; 
}
uint64_t mpow(uint64_t x, string y, uint64_t mod) {
	int N = y.size();
    x %= mod;
	uint64_t ret = 1;
	for(int i=N-1;i>=0;--i) {
		if (y[i]=='1')
			ret = mul(ret, x, mod);
		x = mul(x, x, mod);
	}
	return ret;
} 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    uint64_t x, z;
    string y;
    while(cin >> x >> y >> z) {
        cout << mpow(x, y, z) << '\n';
    }
    return 0;
}