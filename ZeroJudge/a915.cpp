#include<iostream>
#include<algorithm>
using namespace std;

pair<int, int>nums[1002];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>nums[i].first>>nums[i].second;
    sort(nums, nums+N);
    for(int i=0;i<N;i++)
        cout<<nums[i].first<<' '<<nums[i].second<<'\n';
    return 0;
}