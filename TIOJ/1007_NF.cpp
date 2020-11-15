#include<iostream>
#include<algorithm>
#define MSIZE (int )9e2
#define INF 0x3f3f3f3f
using namespace std;

int N, M;
int dp[MSIZE+2];
int light(int x){
    printf("walk x=%d\n", x);
    if (dp[x]!=-INF)
        return dp[x];
    int q = 0;
    for (int i=0;i<=N;i++) {
        if (x-i-1>=0) {
            q = max(light(i)+light(x-i-1), q);
        }
    }
    dp[x] = q;
    return q;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fill(dp, dp+M+1, -INF);
    dp[0] = 0, dp[1] = 2;
    N=2, M=4;
    for(int i=0;i<M;i++)
        cout<<dp[i]<<' ';
    cout<<endl;
    cout<<light(M)<<endl;
    return 0;
}
