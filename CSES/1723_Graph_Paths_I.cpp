#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll ;
typedef vector<vector<ll> > vvi;
typedef vector<ll> vi ;


int N, M, K;
const int MOD = 1e9 + 7;
vvi mul(vvi A, vvi B) {
    vvi C(N, vi(N, 0));
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            for(int k=0;k<N;++k) {
                C[i][j] += A[i][k] * B[k][j] % MOD;
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}
vvi fastpow(vvi matrix, int x) {
    vvi res(N, vi(N, 0));
    for(int i=0;i<N;++i) {
        res[i][i] = 1;
    }
    while(x) {
        if(x&1) {
            res = mul(res, matrix);
        }
        matrix = mul(matrix, matrix);
        x >>= 1;
    }
    return res;
}
int main() {
    cin >> N >> M >> K;
    vvi mp(N, vi(N, 0));
    for(int i=0;i<M;++i) {
        int a, b;
        cin >> a >> b;
        mp[b-1][a-1] ++;
    }
    cout << fastpow(mp, K)[N-1][0] << '\n';
    return 0;
}
