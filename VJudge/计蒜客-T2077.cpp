#include<iostream>
#include<algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, ans=0;
    int nums[102];
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>nums[i];
    sort(nums, nums+N);
    for(int i=2;i<N;i++){
        for(int j=0;j<i;j++){
            for(int k=j+1;k<i;k++){
                if(nums[j]+nums[k]==nums[i]){
                    ans++;
                    goto next;
                }
            }
        }
        next:;
    }
    cout<<ans<<'\n';
    return 0;
}