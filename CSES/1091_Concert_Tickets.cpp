#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


const int MAX_N = 2e5 + 5;
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M;
    cin >> N >> M;

    multiset<int> H;
    vector<int> T(M);
    for(int i=0;i<N;++i) {
        int x;
        cin >> x;
        H.insert(x);
    }
    for(int &i: T) cin >> i;

    for (int i = 0; i < M; i++) {
        auto it = H.upper_bound(T[i]);
        if (it == H.begin()) {
            cout << -1 << endl;
        } else {
            cout << *(--it) << endl;
            H.erase(it);
        }
    }

    return 0;
}