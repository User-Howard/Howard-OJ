#include <iostream>
#include <cmath>
#include <stack>
using namespace std;


int main(){
    int N; 
    int nums[(int)2e5 + 2];
    stack<int> sta;
    cin >> N;
    for(int i=0;i<N;++i){
        cin >> nums[i];
    }
    int ans = 0;
    sta.push(0);
    for(int i=1;i<N;++i){
        while(!sta.empty() and nums[sta.top()] >= nums[i])
            sta.pop();
        if(sta.empty()){
            ans = max(nums[i] * (i+1), ans);
        }
        else{
            ans = max(nums[i] * (sta.top() - i), ans);
        }
        if(!sta.empty())
            cout << sta.top() << '\n';
        else{
            cout << '#' << '\n';
        }
        sta.push(i);
    }
    cout << ans;
    return 0;
}