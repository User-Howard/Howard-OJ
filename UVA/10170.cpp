#include <iostream>
using namespace std;


int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    uint64_t S, D;
    while(cin >> S >> D) {
        uint64_t tmp = 1LL*2*D + 1LL*S*(S-1);
        uint64_t ans = 1;
        while(ans*(ans-1) < tmp) ans++;
        cout << ans-1 << '\n';
    }
    return 0;
}
