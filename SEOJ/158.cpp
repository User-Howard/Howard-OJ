#include <iostream>
#include <vector>
using namespace std;
#define w first
#define d second

const int INF = 0x3f3f3f3f;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T, N, M, K;
    cin >> T;
    while(T--){
        cin >> N >> M >> K;
        vector<pair<int, int> > nums(N);
        vector<int> dp(100005, INF);
        for(auto &i:nums) cin >> i.w >> i.d;
        dp[0] = 0;
        for(int i=0;i<N;++i){
            for(int k=1;k<K;++k){
                for(int j=100005;j>=0;--j){
                    if(j-k*nums[i].d >= 0)
                        dp[j] = min(dp[j], dp[j - k*nums[i].d] + k*nums[i].w);

                }
            }
        }
        for(int i=100004;i>=0;--i)
            if(dp[i] <= M){
                cout << i << '\n';
                break;
            }
    }
    return 0;
}
