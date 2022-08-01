#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <numeric>
using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
#define vE vector<E>

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second


const int INF = 0x3f3f3f3f;
int N;
int answer;
struct E {
    pii D;
    vi G;
};
vE Person;
vi in;
void init() {
    answer = 0;
    in.resize(N);
    fill(all(in), 0);
    Person.resize(N);
    for(int i=0;i<N;++i)
        Person[i].G.clear();
}
pii dfs(int u) {
    if(Person[u].G.size() == 0) {
        Person[u].D = mp(0, 0);
    }
    else {
        vi ct;
        for(int i:Person[u].G) {
            ct.pb(dfs(i).fi + 1);
        }
        sort(all(ct));
        if(ct.size() >= 2)
            Person[u].D = mp(ct[ct.size()-1], ct[ct.size()-2]);
        else if(ct.size() == 1) 
            Person[u].D = mp(ct[0], 0);
        else 
            Person[u].D = mp(0, 0);
    }
    answer = max(Person[u].D.fi + Person[u].D.se, answer);
    return Person[u].D;
}
int solve() {
    init();
    for(int i=0;i<N-1;++i) {
        int u, v;
        cin >> u >> v;
        Person[u].G.pb(v);
        ++in[v];
    }
    int root;
    for(int i=0;i<N;++i) {
        if(in[i] == 0) {
            root = i;
            break;
        }
    }
    dfs(root);
    // for(int i=0;i<N;++i)
    //     cout << i << '\t' << Person[i].D.fi << '\t' << Person[i].D.se << '\n';
    return answer;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> N) {
        cout << solve() << '\n';
    }
    return 0;
}
