#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;



int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int> >nums(N, vector<int>(M, 0));
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j)
            cin >> nums[i][j];
        sort(nums[i].begin(), nums[i].end(), greater<int>());
    }
    int ans = 0, cnt = 0;
    for(int i=0;i<N;++i)
        ans += nums[i][0];
    cout << ans << '\n';
    for(int i=0;i<N;++i){
        if(ans%nums[i][0] == 0){
            cout << nums[i][0] << ' ';
            ++cnt;
        }
    }
    if(cnt == 0)
        cout << -1 << '\n';
    return 0;
}