#include <iostream>
#include <string.h>
using namespace std;


const int MAXN=1e5+7, INF=0x3f3f3f3f;
int money[MAXN][6], dp[MAXN][6];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K;
    cin >> N >> K;
    for(int i=1;i<=N;i++)
        for (int j=1;j<=K;j++)
            cin >> money[i][j];
    for(int i=0;i<=N;++i)
        for(int j=0;j<=K;++j)
            dp[i][j] = -INF;
    dp[0][0] = 0;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=K;j++)
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + money[i][j];
    cout << dp[N][K] << '\n';
    return 0;
}