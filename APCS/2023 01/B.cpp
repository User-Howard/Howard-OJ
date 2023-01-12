#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int K, Q, R;
    cin >> K >> Q >> R;
    vector<string> S(Q+1, string(K, ' '));
    cin >> S[0];
    for(int i=1;i<=Q;++i) {
        vector<int> P(K);
        for(int &j: P) cin >> j;
        for(int j=0;j<K;++j)
            S[i][P[j]-1] = S[i-1][j];
    }
    for(int i=0;i<R;++i) {
        for(int j=1;j<=Q;++j)
            cout << S[j][i];
        cout << '\n';
    }
    return 0;
}