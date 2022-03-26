#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
vector<int> out(6);
int T, N;
void dfs(int x=-1, int idx=0){
    if(idx == 6){
        for(int i=0;i<6;++i)
            cout << out[i] << " \n"[i==5];
        return;
    }
    for(int i=x+1;i<N;++i){
        out[idx] = nums[i];
        dfs(i, idx+1);
    }
}
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        nums.resize(N);
        for(int &i:nums) cin >> i;
        dfs();
    }    
    return 0;
}