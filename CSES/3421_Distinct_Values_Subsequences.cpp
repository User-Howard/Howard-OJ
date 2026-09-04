#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MOD = 1e9+7;
int64_t fpow(int64_t x, int64_t pow) {
    int64_t result = 1;
    x %= MOD;
    while(pow) {
        if(pow&1) result = (result*x) % MOD;
        x = (x*x) % MOD;
        pow >>= 1;
    }
    return result;
}
int64_t inv(int x) {
    return fpow(x, MOD-2);
}
int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for(auto &i: nums) cin >> i;
    map<int, int> mp;
    int64_t auc = 1;
    int64_t ans = 0;
    for(int i=0;i<N;++i) {
        int value = mp[nums[i]];
        auc = auc * inv(value+1) % MOD;
        ans = (ans + auc) % MOD;
        auc = auc*(value+2)%MOD;
        mp[nums[i]] = value + 1;
    }
    cout << ans << '\n';

    return 0;
}
