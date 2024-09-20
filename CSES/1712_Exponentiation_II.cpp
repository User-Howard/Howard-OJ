#include <iostream>
#include <algorithm>
using namespace std;


const int MOD = 1e9+7;
int eulerTotient(int n) {
    int result = n;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p)
            continue;
        while(n % p == 0) {
            n /= p;
        }
        result -= result / p;
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}
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
int main() {
    // cout << eulerTotient(MOD);
    int T;
    cin >> T;
    while(T--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, solve(b, c, 1e9+6)) << '\n';
    }
    return 0;
}
