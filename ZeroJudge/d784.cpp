#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;


void solve(){
    int N, ans, nums[102], dp[102]={0};
    cin >> N;
    for(int i=0;i<N;++i) cin >> nums[i];
    ans = dp[0] = nums[0];
    for(int i=1;i<N;++i){
        dp[i] = max(nums[i], dp[i-1]+nums[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int K;
    cin >> K;
    while(K--)
        solve();
	return 0;
}