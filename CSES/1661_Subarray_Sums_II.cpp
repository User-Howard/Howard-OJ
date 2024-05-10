#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


const int MAX_N = 2e5 + 5;

int N, M;
int Nums[MAX_N];
int64_t prefix[MAX_N];
int main() {
    cin >> N >> M;
    for(int i=0;i<N;++i)
        cin >> Nums[i];
    for(int i=0;i<N;++i) {
        prefix[i] = Nums[i];
        if(i != 0) prefix[i] += prefix[i-1];
    }
    map<int64_t, int> mp;
    mp[0] = 1;
    uint64_t answer = 0;
    for(int i=0;i<N;++i) {
        if(mp.find(prefix[i]-M) != mp.end()) answer += mp[prefix[i]-M];
        mp[prefix[i]] += 1;
    }
    cout << answer << '\n';
    return 0;
}
