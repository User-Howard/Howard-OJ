#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int > nums, pre;
const int Mod = 10000019;
uint64_t ans = 0;
void count(int l, int r){ // [l, r)
    if(r - l <= 1)
        return;
    int mid = l + (r - l) / 2;
    count(l, mid); count(mid, r);
    int ci = l;
    for(int i=mid;i<r;++i){
        while(ci < mid and nums[ci] < nums[i]) ++ci;
        ans += pre[mid-1] - pre[ci-1];
        ans += mid - ci;
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
    nums.resize(N); pre.resize(N);
    for(int &i:nums) cin >> i;
    pre[0] = nums[0];
    for(int i=1;i<N;++i)
        pre[i] = pre[i-1] + nums[i];
    count(0, N);
    cout << ans << '\n';
    return 0;
}
