#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;


int N;
int nums[1002];
int dp[1002][1002];
// get the min "branch degree" of [a, b)
int get_branch_min(const int a, const int b){
    if(dp[a][b]!=-1)
        return dp[a][b];
    int MIN = 2e9;
    if(b-a==2)
        MIN = nums[a]+nums[a+1];
    else{
        for(int i=a+2;i<b;i++)
            MIN = min(max(get_branch_min(a+1, i), get_branch_min(i, b)), MIN);
        MIN += nums[a];
    }
    return dp[a][b] = MIN;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    uint64_t MIN = 0, MAX = 0;
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> nums[i];
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<N;i++){
        dp[i][i+1] = nums[i];
        MAX += nums[i];
    }
    MIN = get_branch_min(0, N);
    cout << MIN << ' ' << MAX << '\n';
    return 0;
}