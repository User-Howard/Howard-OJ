#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


const int MAX_N = 1e5 + 2;
vector<int> PS;
void build_prime_table() {
    PS.emplace_back(0);
    vector<bool> prime(MAX_N, true);
    for(int i = 2;i<MAX_N;++i) {
        if(prime[i]) {
            PS.emplace_back(PS[PS.size()-1]+i);
            for(int j = 2;i*j<MAX_N;++j) {
                prime[i*j] = false;
            }
        }
    }
}
int main() {
    build_prime_table();
    int N;
    const int PS_size = PS.size();
    while(cin>>N and N!=0) {
        int ans = 0;
        for(int i = 0;i<PS_size-1;++i) {
            if(PS[i+1]-PS[i]>N)
                break;
            auto t = find(PS.begin(), PS.end(), PS[i]+N);
            if(t!=PS.end()) ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}