#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct query {
    char op;
    int v, w;
    int id;
};
const int maxn = 3e5+5;
int N;
vector<int> G[maxn];
int revG[maxn];
int stacks[maxn];

int dep[maxn];
int pt = 0;
int pos[maxn];
int spt[maxn<<1][21];
void dfs(int x, int depth=0, int pre=-1) {
    dep[x] = depth;
    pos[x] = pt;

    spt[pt++][0] = dep[x];
    for(int v: G[x]) {
        if(v==pre) continue;
        dfs(v, depth+1, x);
        spt[pt++][0] = dep[x];
    }
}


int main() {
    fill(stacks, stacks+maxn, 0);
    cin >> N;
    vector<query> Queries(N);
    for(int i=1;i<=N;++i) {
        auto& [op, v, w, id] = Queries[i-1];
        id = i;
        cin >> op >> v;
        if(op=='a') {
            stacks[i] = i;
            revG[i] = stacks[v];
            G[stacks[v]].push_back(i);
        } else if(op=='b') {
            stacks[i] = revG[stacks[v]];
        } else {
            cin >> w;
            stacks[i] = stacks[v];
        }
    }
    dfs(0);
    for(int i=1;i<21;++i){ 
        for(int j=0;j+(1<<i)<pt;++j) {
            spt[j][i] = min(spt[j][i-1], spt[j+(1<<(i-1))][i-1]);
        }
    }
    for(auto [op, v, w, id]: Queries) {
        if(op=='b') {
            cout << stacks[v] << '\n';
        } else if(op=='c') {
            if(stacks[v]==stacks[w]) {
                cout << dep[stacks[v]] << '\n';
            } else {
                int a = min(pos[stacks[v]], pos[stacks[w]]);
                int b = max(pos[stacks[v]], pos[stacks[w]]);
                int l = log2(b-a);
                int accDep = min(spt[a][l], spt[b-(1<<l)+1][l]);
                cout << accDep << '\n';
            }
        }
    }
    return 0;
}
