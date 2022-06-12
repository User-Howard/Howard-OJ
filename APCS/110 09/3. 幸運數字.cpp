#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> nums[(int)3e5];
int arr[(int)3e5];
int64_t presum[(int)3e5] = {0};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;++i)
        nums[i].second = i + 1, cin >> nums[i].first;
    for(int i=1;i<=N;++i){
        presum[i] = presum[i-1] + nums[i-1].first;
        arr[i] = nums[i-1].first;
    }
    sort(nums, nums+N);
    int pointer = 0;
    int l = 1, r = N;
    while(l < r and pointer<=N){
        int m = nums[pointer++].second;
        if(m < l or r < m)
            continue;
        // cout << m << '\n';
        int lsum = presum[m - 1] - presum[l - 1];
        int rsum = presum[r] - presum[m];
        // // cout << lsum << ' ' << rsum << '\n';
        if(lsum > rsum)
            r = m - 1;
        else
            l = m + 1;
        // cout << l << '\t' << r << '\n' << '\n';
    }
    cout << arr[l] << '\n';
    return 0;
}
