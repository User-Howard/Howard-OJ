#include <iostream>
#include <vector>
using namespace std;


const int INF = 0x3f3f3f3f;
int T, N;
vector<int> nums, pre;
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        nums.resize(N); pre.resize(N+1);
        for(int &i:nums) cin >> i;
        vector<vector<int> > dp(N, vector<int>(N, INF));
        for(int i=1;i<=N;++i) pre[i] = pre[i-1] + nums[i-1];
        for(int i=0;i<N;++i)
            dp[i][i] = 0;
        for(int len=2;len<=N;++len){
            for(int l=0;l+len<=N;++l){
                int r = l + len - 1;
                for(int j=l;j<r;++j)
                    dp[l][r] = min(dp[l][j]+dp[j+1][r] + pre[r+1] - pre[l], dp[l][r]);
            }
        }
        cout << dp[0][N-1] << '\n';
    }
    return 0;
}