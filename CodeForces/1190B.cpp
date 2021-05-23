#include<iostream>
#include<algorithm>
using namespace std;

int N;
bool ans=false;
int nums[(int)(1e5)+2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>nums[i];
    sort(nums, nums+N);
    int threat=0;
    for(int i=0;i<N;i++){
        if(2<=N && nums[0]==0 && nums[1]==0){
            ans = 0;
            break;
        }
        if(i+1<N && nums[i]==nums[i+1]){
            threat++;
        }
        if (i+2<N && nums[i]+1==nums[i+1] && nums[i+1]==nums[i+2]){
            ans = 0;
            break;
        }
        ans ^= (bool)((nums[i]-i)%2);
    }
    if(ans && threat<=1)
        cout<<"sjfnb"<<'\n';
    else
        cout<<"cslnb"<<'\n';
    return 0;
}