#include <iostream>
#include <cmath>
#include <stack>
using namespace std;


struct E{
    uint64_t h, l, r;
    E(uint64_t h_, uint64_t l_, uint64_t r_){
        h = h_, l = l_, r = r_;
    }
};
int main(){
    int N; 
    int nums[(int)2e5 + 2];
    stack<E > sta;
    cin >> N;
    for(int i=1;i<=N;++i){
        cin >> nums[i];
    }
    uint64_t ans = 0;
    sta.push(E(0, 0, 0));
    for(int i=1;i<=N;++i){
        while(sta.top().h >= nums[i]){
            E p = sta.top(); sta.pop();
            ans = max(ans, p.h * (i - p.l));
        }
        sta.push(E(nums[i], sta.top().r + 1, i));
    }
    while(sta.top().h > 0){
        E p = sta.top(); sta.pop(); 
        ans = max(ans, p.h * (N - p.l + 1));
    }
    cout << ans << '\n';
    return 0;
}