#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {

    int N, T;
    cin >> N >> T;
    vector<pair<int, int> > G(T);
    for(int i=0;i<T;++i) {
        G[i] = make_pair(0, -i);
    }
    vector<pair<int, int> > V(N);
    for(int i=0;i<N;++i) {
        int x, t;
        cin >> x >> t;
        V[i] = make_pair(t, x);
    }
    sort(V.begin(), V.end());
    for(int i=0;i<N;++i) {
        int x = V[i].second;
        int t = V[i].first;
        int minIndex = distance(G.begin(), min_element(G.begin(), G.begin()+min(t+1, T)));
        G[minIndex].first = max(G[minIndex].first, x);
    }
    uint64_t answer = 0;
    for(auto i: G) {
        answer += i.first;
    }
    cout << answer << '\n';
    return 0;
}