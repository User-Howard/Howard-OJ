#include <iostream>
using namespace std;



uint64_t qpow(uint64_t x, uint64_t u, uint64_t mod) {
    uint64_t ans = 1;
    while(u) {
        if(u & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        u >>= 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int R, N, Y;
    while(cin >> R >> N >> Y and not (R==0 and N==0 and Y==0)) {
        int ans = 0;
        for(int i=(N==0);i<Y;++i) {
            ans += (int)(qpow(i, N, Y) == R);
        }
        cout << ans << '\n';
    }
    return 0;
}