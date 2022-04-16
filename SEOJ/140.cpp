#include <iostream>
using namespace std;


const int Mod = 1e6 + 7;
const int MAX_N = 1e5 + 2;
int dp[MAX_N][3][3];
int main(){
    dp[1][0][0] = dp[1][1][1] = dp[1][2][2] = 1;
    for(int i=2;i<MAX_N;++i){
        for(int j=0;j<3;++j){
            dp[i][0][j] = (dp[i-1][0][j] + dp[i-1][1][j] + dp[i-1][2][j])%Mod;
            dp[i][1][j] = (dp[i-1][0][j] + dp[i-1][1][j])%Mod;
            dp[i][2][j] = (dp[i-1][0][j] + dp[i-1][2][j])%Mod;
        }
    }
    int T;
    cin >> T;
    int n;
    while(T--){
        cin >> n;
        cout << (dp[n][0][0] + dp[n][0][1] + dp[n][0][2] + dp[n][1][0] + dp[n][1][1] + dp[n][2][0] + dp[n][2][2])%Mod<< '\n';        
    }
    return 0;
}