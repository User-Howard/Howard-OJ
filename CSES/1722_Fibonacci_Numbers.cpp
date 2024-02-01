#include <iostream>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
struct E{
    ll x[2][2];
    E(ll a=0, ll b=0, ll c=0, ll d=0) {
        x[0][0] = a, x[0][1] = b;
        x[1][0] = c, x[1][1] = d;
    }
};
E mat(const E A, const E B) {
    E RET(0, 0, 0, 0);
    for(int i=0;i<2;++i) {
        for(int j=0;j<2;++j) {
            for(int k=0;k<2;++k) {
                RET.x[i][j] += A.x[i][k]*B.x[k][j];
                RET.x[i][j] %= MOD;
            }
        }
    }
    return RET;
}
E solve(E T, ll x) {
    E RET(1, 0, 0, 1);
    while(x) {
        if(x&1) RET = mat(RET, T);
        x >>= 1;
        T = mat(T, T);
    }
    return RET;
}
int main() {
    ll N;
    cin >> N;
    E ans = solve(E(0, 1, 1, 1), N);
    cout << ans.x[0][1] << '\n';
    return 0;
}