#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define all(x) x.begin(),x.end()
#define int int64_t


const int MAX_N = 2e5+5;
const int INF = 1e9;
int N, M;
map<int, int> mp;
int sum[MAX_N];
int cnt[MAX_N];
int root[MAX_N];

int t;
int nodeIndex;
void init() {
    nodeIndex = 0;
    mp.clear();
}
int find(int x) {
    if(root[x] == x) return x;
    return root[x] = find(root[x]);
}
void union_set(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if(pa==pb) return;
    if(cnt[pa] < cnt[pb]) {
        swap(pa, pb);
    } 
    cnt[pa] += cnt[pb]; cnt[pb]=0;
    sum[pa] += sum[pb];
    root[pb] = pa;
}
void transfer_set(int a, int b, int value) {
    nodeIndex++;
    int pa = find(a);
    int pb = find(b);
    if(pa==pb) return;
    sum[pb] += value;
    sum[pa] -= value;
    cnt[pb] ++;
    cnt[pa] --;

    root[nodeIndex] = pb;
    sum[nodeIndex] = value;
    cnt[nodeIndex] = 1;
    mp[value] = nodeIndex;
}
void solve() {
    mp.clear();
    vector<tuple<int, int, int> > In;
    for(int i=0;i<M;++i) {
        int a, b, c=0;
        cin >> a >> b;
        if(a!=3)
            cin >> c;
        In.push_back(make_tuple(a, b, c));
    } 
    for(int i=1;i<=N;++i) {
        mp[i] = i;
        sum[i] = i;
        cnt[i] = 1;
        root[i] = i;
        nodeIndex = i+1;
    }
    for(t=0;t<M;++t) {
        auto [op, a, b] = In[t];
        if(op==1) {
            union_set(mp[a], mp[b]);
        } else if(op==2) {
            transfer_set(mp[a], mp[b], a);
        } else {
            // cerr << "Getting " << find(mp[a]) << "'s data\n";
            cout << cnt[find(mp[a])] << ' ' << sum[find(mp[a])] << '\n';
        }
    }
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin >> N >> M) {
        solve();
    }
    return 0;
}