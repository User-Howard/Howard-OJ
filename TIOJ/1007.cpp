#include<iostream>
#include<cmath>
#define ll long long
using namespace std;


ll dp[100];
int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin>>N>>M;
    for (int i=0;i<=N;i++)
        dp[i] = pow(2, i);
    for(int i=N+1;i<=M;i++){
        for(int j=1;j<=N+1&&i-j>=0;j++){
            dp[i] += dp[i-j];
        }
    }
    cout<<dp[M]<<endl;
    return 0;
}
