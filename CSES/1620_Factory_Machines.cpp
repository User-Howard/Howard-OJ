#include <iostream>
#include <algorithm>
using namespace std;


const int MAX_N = 2e5 + 10;
int64_t N, T;
int Time[MAX_N];
int64_t solve(int64_t time) {
    int64_t count = 0;
    for(int i=0;i<N;++i) {
        count += time / Time[i];
        if(count > T) break;
    }
    return count;
}
int main() {
    cin >> N >> T;
    for(int i=0;i<N;++i)
        cin >> Time[i];
    int64_t l = 0, r = 1e18 + 10;
    while(r-l > 1) {
        const int64_t mid = l+(r-l)/2;
        if(T <= solve(mid)) r = mid;
        else                l = mid;
    }
    cout << r << '\n';
    return 0;
}
