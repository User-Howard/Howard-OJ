#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;


int N;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    vector<uint64_t> Vecs(N);
    unordered_map<uint64_t, int> Mp;
    for(int i=0;i<N;++i) {
        double t;
        cin >> t;
        Vecs[i] = (uint64_t)(1e9)*t;
        Mp[Vecs[i]] ++;
    }
    uint64_t cnt = 0;
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            // cnt += Mp[Vecs[i] + Vecs[j]];
            for(int k=0;k<N;++k) {
                if (Vecs[i] + Vecs[j] == Vecs[k])
                    ++cnt;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
