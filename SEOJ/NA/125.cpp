#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int > nums;
const int Mod = 10000019;
uint64_t ans = 0;
void count(int l, int r){ // [l, r)
    if(r - l <= 1)
        return;
    int mid = l + (r - l) / 2;
    count(l, mid); count(mid, r);
    int ci = l;
    vector<uint64_t> pre(mid-l+1);
    for(int i = l;i<mid;++i) {
        pre[i-l+1] = pre[i-l] + nums[i];
    }
    for(int i = mid;i<r;++i) {
        while(ci < mid and nums[ci] <= nums[i]) ++ci;
        if(ci >= mid) continue;
        ans += pre[mid-l] - pre[ci-l];
        ans %= Mod;
        ans += (mid-ci)*nums[i];
        ans %= Mod;
    }
    vector<int> tmp(r-l);
    merge(nums.begin()+l, nums.begin()+mid, nums.begin()+mid, nums.begin()+r, tmp.begin());
    copy(tmp.begin(), tmp.end(), nums.begin()+l);
    return;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    nums.resize(N);
    for(int &i:nums) cin >> i;
    count(0, N);
    cout << ans << '\n';
    return 0;
}
