#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> Nums;
vector<int> pre;
vector<int> dp;
void init() {
    Nums.resize(N+1);
    pre.resize(N+1);
    dp.resize(N+1);
}
void build_pre() {
    vector<bool> visit(int(1e5+2));
    int pointer = 1;
    for(int i=1;i<=N;++i) {
        while(visit[Nums[i]]) {
            visit[Nums[pointer++]] = false;
        }
        visit[Nums[i]] = true;
        pre[i] = pointer;
    }
}
int solve() {
    for(int k=0;k<K;++k) {
        for(int i=N;i>=1;--i) {
            dp[i] = max(dp[i], dp[pre[i]-1]+i-pre[i]+1);
        }
    }

    return *max_element(dp.begin(), dp.end());
}
int main() {
    cin >> N >> K;
    init();
    for(int i=1;i<=N;++i) {
        cin >> Nums[i];
    }
    build_pre();
    cout << solve() << '\n';

    return 0;
}