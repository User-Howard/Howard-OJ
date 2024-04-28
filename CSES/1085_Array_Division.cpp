#include <iostream>
#include <algorithm>
using namespace std;


const int MAX_N = 2e5 + 5;
int N, M;
int Nums[MAX_N];
bool isAvailable(uint64_t x) {
    // cerr << "Call isAvailable(" << x << ")\n";
    uint64_t tmp = x;
    int cnt = 0;
    for(int i=0;i<N;++i) {
        if(x < Nums[i]) return false;
        if(tmp + Nums[i] > x) {
            tmp = 0;
            ++cnt;
            if(cnt>M) return false;
        }
        tmp += Nums[i];
    }
    return true;
}
int main() {
    cin >> N >> M;
    uint64_t l = 0, r=2e14 + 10;
    for(int i=0;i<N;++i) {
        cin >> Nums[i];
    }
    while(r-l > 1) {
        // cerr << l << ' ' << r << '\n';
        const uint64_t mid = l + (r-l) / 2;
        if(isAvailable(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }

    }
    cout << r << '\n';
    return 0;
}
