#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=(int )1e4+5;

int N;
int nums[MAXN];
int prefix[MAXN];
int dp[MAXN][MAXN];
int The_sum_of(int l, int r){
    return prefix[r-1]-prefix[l-1];
}
int Game(int l, int r){
    if(dp[l][r]!=-INF){
        return dp[l][r];
    }
    int q = max(0, 0);
    return 0;
}
int main(){
    cin>>N;
    memset(dp, 1, sizeof(dp));
    memset(prefix, 0, sizeof(prefix));
    for(int i=0;i<N;i++){
        cin>>nums[i];
        prefix[i+1] = nums[i]+prefix[i];
    }
    // 在Left==Right時, dp[l][r] 相當於 nums[l]
    for(int i=0;i<N;i++){
        dp[i][i] = nums[i];
    }
    cout<<Game(0, N-1)<<endl;
    for(int i=0;i<MAXN;i++){
        for(int j=0;j<MAXN;j++){
            cout<<dp[i][j]<<'\t';
        }
        cout<<endl;
    }
    return 0;
}
