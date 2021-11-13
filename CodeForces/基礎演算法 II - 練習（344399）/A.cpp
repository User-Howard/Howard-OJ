#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int N;
vector<int> nums;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    nums.resize(N);
    for(int i=0;i<N;++i)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    bool have_triangle = false;
    for(int i=2;i<N;++i)
        if(nums[i-2] + nums[i-1] > nums[i])
            have_triangle = true;
    cout << (have_triangle ? "Yes" : "No") << '\n';
    return 0;
}