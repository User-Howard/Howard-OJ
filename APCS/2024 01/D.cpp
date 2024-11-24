#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


const int INF = 0x3f3f3f3f;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;++i)
        cin >> A[i];
    vector<vector<int> > dp(N, vector<int>(N, INF));
    for(int i=0;i<N;++i) dp[i][i] = A[i];
    for(int i=1;i<N;++i) {
        for(int j=0;j+i<N;++j) {
            for(int k=0;k<i;++k)
                dp[j][j+i] = min(dp[j][j+k]+dp[j+k+1][j+i]+, dp[j][j+i]);
        }
    }
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            if(dp[i][j]==INF)
                cout << "INF\t";
            else
                cout << dp[i][j] << '\t';
        }
        cout << '\n';
    }
    cout << dp[0][N-1] << '\n';
    return 0;
}
