#include <iostream>
#include <vector>
using namespace std;


int main() {
    // freopen("out.txt", "w", stderr);
    uint64_t N, K;
    cin >> N >> K;
    vector<int64_t> Primes(20);
    for(int i=0;i<K;++i) {
        cin >> Primes[i];
    }
    /*
    for(int i=0;i<K;++i) {
        cerr << i << ": " << Primes[i] << '\n';
    }
    */
    int64_t answer = 0;
    for(uint64_t i=1;i<(1LL<<K);++i) {
        int sign = __builtin_popcount(i)%2 ? 1 : -1;
        __uint128_t t = 1;
        for(int j=0;j<K;++j) {
            if(i&(1LL<<j)) {
                t *= Primes[j];
            }
            if(t>N) break;
        }
        answer += sign*(N/(1LL*t));
        // cerr << i << '>' << N << ' ' << (int)t << " " << answer << '\n';
    }
    cout << answer << '\n';
    return 0;
}
