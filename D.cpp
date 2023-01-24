#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
#define lower(x) x&-x

const int MAX_N = 1e8+5;
vector<uint16_t> BIT(MAX_N);
int query(int x) {
    x+=5;
    int ret = 0;
    for(int i=x;0<i;i-=lower(i))
        ret += BIT[i];
    return ret;
}
void update(int x, int u) {
    x+=5;
    for(int i=x;i<MAX_N;i+=lower(i)) 
        BIT[i] += u;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    vector<pair<int, int> > V(N);
    for(int i=0;i<N;++i) {
        cin >> V[i].second;
    }
    for(int i=0;i<N;++i) {
        cin >> V[i].first;
    }
    sort(V.begin(), V.end());
    int ans = 0;
    priority_queue<int, vector<int>, greater<int> > Add;
    update(-1, K);
    for(int i=0;i<N;++i) {
            // cout << V[i].second << ' ' << V[i].first << '\n';
        while((!Add.empty()) and Add.top() < V[i].second) {
            update(Add.top()+1, 1);
            Add.pop();
        }
        if(query(V[i].second)>0) {
            ans += 1;
            update(V[i].second, -1);
            Add.push(V[i].first);
        }
    }
    cout << ans << '\n';
    return 0;
}