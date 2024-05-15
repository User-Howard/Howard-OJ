#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


const int64_t MAX_N = 2e9;
vector<int> prime;
bool prime_table[44724];
void make_prime_number() {
    fill(prime_table, prime_table+44724, 1);

    for(int i=2;i<=44724;++i) {
        if(prime_table[i]) {
            for(int j=2;i*j<=44724;++j) {
                prime_table[i*j] = 0;
            }
            prime.push_back(i);
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    make_prime_number();
    int N;
    while(cin >> N) {
        uint64_t answer = 0;
        for(int i: prime) {
            if(N%i==0) {
                while(N%i==0) {
                    answer += i;
                    N /= i;
                }
            }
        }
        if(N!=1) cout << N << '\n';
        else cout << answer << '\n';
    }
    return 0;
}
