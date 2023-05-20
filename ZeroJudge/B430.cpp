#include <iostream>
using namespace std;



uint64_t qadd(uint64_t x, uint64_t u, uint64_t mod) {
    uint64_t ans = 0;
    while(u) {
        if(u & 1)
            ans = (ans + x) % mod;
        x = (2 * x) % mod;
        u >>= 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    uint64_t A, B, N;
    while(cin >> A >> B >> N) {
        cout << qadd(A%N, B%N, N) << '\n';
    }
    return 0;
}