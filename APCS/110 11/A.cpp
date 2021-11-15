#include <iostream>
#include <cmath>
using namespace std;


int N;
int nums[102];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;++i)
        cin >> nums[i];
    int cnt = 0;
    if(nums[0] == 0)
        cnt += nums[1];
    if(nums[N-1] == 0)
        cnt += nums[N-2];
    for(int i=1;i<N-1;++i){
        if(nums[i] == 0)
            cnt += min(nums[i-1], nums[i+1]);
    }
    cout << cnt << '\n';
    return 0;
}