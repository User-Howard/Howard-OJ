#include <iostream>
#include <vector>
using namespace std;


int main() {
    int K, Q, R;
    cin >> K >> Q >> R;
    vector<string> S(Q+1, string(K, ' '));
    cin >> S[0];
    for(int i=0;i<Q;++i) {
        for(int a, j=0;j<K;++j) {
            cin >> a;
            S[i+1][a-1] = S[i][j];
        }
    }
    for(int i=0;i<R;++i) {
        for(int j=1;j<=Q;++j)
            cout << S[j][i];
        cout << '\n';
    }
    return 0;
}