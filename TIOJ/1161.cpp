#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
int T, N, K;
int main(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        vector<pair<int, int> > nums(N);
        for(int i=0;i<N;++i)
            cin >> nums[i].first >> nums[i].second;
        sort(nums.begin(), nums.end());
        priority_queue<int, vector<int>, less<int> > prque;
        int ans = INF;
        for(int i=1;i<=N;++i){
            prque.push(nums[i-1].second);
            while(prque.size() > K)
                prque.pop();
            if(i >= K)
                ans = min(prque.top() + nums[i-1].first, ans);
        }
        cout << ans << '\n';
    }
    return 0;
}