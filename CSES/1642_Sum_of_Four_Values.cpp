#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>
using namespace std;


int main() {
    int N, X;
    cin >> N >> X;
    vector<int> Nums(N);
    map<uint64_t, priority_queue<pair<int, int> > > rec;
    for(int &i: Nums) cin >> i;
    for(int i=0;i<N;++i) {
        for(int j=i+1;j<N;++j)
        rec[0LL+Nums[i]+Nums[j]].push(make_pair(i, j));
    }
    for(int i=0;i<N;++i) {
        for(int j=i+1;j<N;++j) {
            const uint64_t rest = 0LL+X-Nums[i]-Nums[j];
            if(rec.find(rest)==rec.end()) continue;
            auto tmp = rec[rest].top();
            if(tmp.first > j) {
                cout << i+1 << ' ' << j+1 << ' ' << tmp.first+1 << ' ' << tmp.second+1 << '\n';
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
