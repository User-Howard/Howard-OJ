#include <iostream>
using namespace std;


const int MOD = 1e9+7;
struct Matrix {
    int64_t data[6][6]={0};
    int64_t* operator[](int i) {
        return data[i];
    }
    Matrix operator*(Matrix &b) {
        Matrix c;
        for(int i=0;i<6;i++) {
            for(int j=0;j<6;j++) {
                for(int k=0;k<6;k++) {
                    c.data[i][j]+=data[i][k]*b.data[k][j] % MOD;
                    c.data[i][j]%=MOD;
                }
            }
        }
        return c;
    }
};
Matrix fastpow(Matrix a, int64_t n) {
    Matrix ans;
    for(int i=0;i<6;++i)
        ans[i][i] = 1;
    while(n) {
        if(n&1) {
            ans=ans*a;
        }
        a=a*a;
        n>>=1;
    }
    for(int i=0;i<6;++i) {
        for(int j=0;j<6;++j) {
            cerr << ans[i][j] << "\t";
        }
        cerr << '\n';
    }
    return ans;
}
int main() {
    int64_t N;
    cin >> N;
    Matrix T;
    for(int i=0;i<5;++i)
        T[i][i+1] = 1;
    for(int i=0;i<6;++i)
        T[5][i] = 1;
    Matrix ans = fastpow(T, N);
    cout << ans[5][5];
    return 0;
}
