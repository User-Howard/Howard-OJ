#include <iostream>
#include <vector>
#include <array>
using namespace std;
#define eb emplace_back
#define lowbit(x) (x&-x)
#define int int64_t


const int MAX_N = 2e5+5;

int N, Q;
array<vector<int>, MAX_N> G;
array<int, MAX_N> parent;
array<int, MAX_N> V;
array<int, MAX_N> in;
array<int, MAX_N> out;

void dfs(int p=1, int prev=-1) {
    static int index=1;
    in[p] = index++;
    for(auto i: G[p]) {
        if(i==prev) continue;
        dfs(i, p);
    }
    out[p] = index++;
}
array<int, MAX_N*2> BIT;
void update(int p, int x) {
    for(int i=p;i<=MAX_N*2;i+=lowbit(i)) {
        BIT[i] += x;
    }
}

int query(int p) {
    int answer = 0;
    for(int i=p;i>0;i-=lowbit(i)) {
        answer += BIT[i];
    }
    return answer;
}

signed main(){
    cin >> N >> Q;
    for(int i=1;i<=N;++i) cin >> V[i];
    for(int i=1;i<N;++i) {
        int a, b;
        cin >> a >> b;
        G[a].eb(b);
        G[b].eb(a);
    }
    dfs();
    for(int i=1;i<=N;++i) {
        update(in[i], V[i]);
        update(out[i], -V[i]);
    }
    int op, s, x;
    while(Q--) {
        cin >> op;
        if(op==1) {
            cin >> s >> x;
            update(in[s], x-V[s]);
            update(out[s],-x+V[s]);
            V[s] = x;
        } else {
            cin >> s;
            cout << query(in[s]) << '\n';
        }
    }
 
    return 0;
}