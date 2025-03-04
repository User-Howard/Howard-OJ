#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string A, B;
    cin >> A >> B;
    vector<vector<int> > dp(A.size()+1, vector<int>(B.size()+1));
    for(int i=0;i<=A.size();++i) {
        dp[i][0] = i;
    }
    for(int i=0;i<=B.size();++i) {
        dp[0][i] = i;
    }
    
    for(int i=1;i<=A.size();++i) {
        for(int j=1;j<=B.size();++j) {
            if(A[i-1]==B[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]);
            }
        }
    }
    cout << dp[A.size()][B.size()] << '\n';
    return 0;
}