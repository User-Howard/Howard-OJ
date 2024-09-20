#include <iostream>
#include <algorithm>
using namespace std;


int64_t solve(int64_t a, int64_t b, const int64_t MOD=1e9+7) {
    int64_t answer = 1;
    while(b) {
        if(b&1) {
            answer = (a%MOD)*(answer%MOD) % MOD;
        }
        a = a*a % MOD;
        b >>= 1;
    }
    return answer;
}
int64_t ex(int64_t a, int64_t b, const int64_t MOD=1e9+7) {
    if(b==0) return 1;
    if(b == 1) return a;
    int64_t tmp = ex(a, b>>1);
    return (tmp*tmp % MOD)*(b&1 ? a : 1) % MOD;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        int a, b;
        cin >> a >> b;
        // cout << solve(a, b) << '\n';
        cout << ex(a, b) << '\n';
    }
    return 0;
}
