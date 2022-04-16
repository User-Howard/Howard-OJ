#include <iostream>
using namespace std;


const int MAX_N = 1e5+2;
const int Mod = 1000007;
int dp[MAX_N][2];
int main(){
    int T;
    dp[0][0] = 1; dp[0][1] = 1;
    dp[1][0] = 0; dp[1][1] = 2;
    dp[2][0] = 3; dp[2][1] = 0;
    for(int i=3;i<MAX_N;++i){
        dp[i][0] = (dp[i-2][0] + dp[i-1][1])% Mod;
        dp[i][1] = (2*dp[i-2][1] + dp[i-1][0] + dp[i-3][0])% Mod;
    }
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout << dp[n][0] << '\n';
    }
    return 0; 
}