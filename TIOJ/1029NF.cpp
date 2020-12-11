#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=(int )1e4+10;

int N;
int nums[MAXN];
int prefix[MAXN];
int dp[MAXN][MAXN];
int The_sum_of(int l, int r){
    return prefix[r+1]-prefix[l];
}
int Game(int l, int r){
    // printf("Call %d %d\n", l, r);
    if(dp[l][r]>0){
        return dp[l][r];
    }
    int q = max(The_sum_of(l+1, r)-Game(l+1, r)+nums[l], The_sum_of(l, r-1)-Game(l, r-1)+nums[r]);
    dp[l][r] = q;
    return q;
}
int main(){
    cin>>N;
    memset(dp, 0, sizeof(dp));
    memset(prefix, 0, sizeof(prefix));
    for(int i=0;i<N;i++){
        cin>>nums[i];
        prefix[i+1] = nums[i]+prefix[i];
    }
    // 在Left==Right時, dp[l][r] 相當於 nums[l]
    for(int i=0;i<N;i++){
        dp[i][i] = nums[i];
    }
    cout<<Game(0, N-1)<<' '<<The_sum_of(0, N-1)-Game(0, N-1)<<endl;
    /*
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<dp[i][j]<<'\t';
        }
        cout<<endl;
    }
    */
    return 0;
}
