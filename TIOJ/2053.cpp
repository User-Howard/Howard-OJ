#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


const int MOD = 1e9 + 7;
typedef vector<uint64_t> vi;
typedef vector<vector<uint64_t> > vvi;
vvi operator*(vvi a, vvi b) {
    vvi ret(2, vi(2, 0));
    for(int i=0;i<2;++i) {
        for(int j=0;j<2;++j) {
            for(int k=0;k<2;++k) {
                ret[i][j] += a[i][k]*b[k][j];
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}
vvi pow(vvi u, int idx) {
    idx--;
    vvi ret = u;
    vvi p = u;
    while(idx) {
        if(idx&1)
            ret = ret * p;
        p = p*p;
        idx >>= 1;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vvi matrix = vvi(2, vi(2, 0));
    int x1, x2, A, B, N;
    cin >> x1 >> x2 >> A >> B >> N;
    matrix[0][0] = 0, matrix[0][1] = 1;
    matrix[1][0] = A, matrix[1][1] = B;

    vvi ans = pow(matrix, N-1) ;
    cout << (ans[0][0]*x1 + ans[0][1]*x2) %MOD<< '\n';
    

    return 0;
}