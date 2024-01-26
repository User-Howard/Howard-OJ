#include <iostream>
using namespace std;


const int MOD = 1e9 + 7;
uint64_t pow_(uint64_t x, int r) {
    uint64_t ans = 1;
    while(r) {
        if(r&1) {
            ans = (ans*x) % MOD;
        }
        x = (x*x)% MOD;
        r >>= 1;
    }
    return ans%MOD;
}
int main() {
    int N;
    cin >> N;
    cout << pow_(2, N) << '\n';
    return 0;
}
