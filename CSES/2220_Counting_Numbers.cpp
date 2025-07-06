#include <iostream>
using namespace std;
typedef long long int ll;

ll solve(string S) {
    ll dp[19][10];
    for(int i=0;i<S.size();++i) {
        int d = S[i] - '0';
        if(i) {
            for(int j=0;j<10;++j) {
                for(int k=0;k<10;++k) {
                    if(k!=0 and j==k) continue;
                    dp[i][j] += dp[i-1][k];
                }
            }
            for(int j=d+1;j<10;++j) {
                dp[i][j] -= 1;
            }
        } else {
            for(int i=0;i<=d;++i) {
                dp[0][i] = 1;
            }
        }
        for(int j=0;j<10;++j) {
            cout << dp[i][j]<<"\t";
        }
        cout << endl;
    }

}
int main() {
    string A, B;
    cin >> A >> B;
    solve(A);
    return 0;
}
