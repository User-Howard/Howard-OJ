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

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

const int INF = 0x3f3f3f3f;
int C, S, Q;
void solve() {
    vvi F(C+1, vi(C+1, INF));
    for(int i=0;i<S;++i) {
        int c1, c2, d;
        cin >> c1 >> c2 >> d;
        F[c1][c2] = F[c2][c1] = d;
    }
    for(int k=1;k<=C;++k) {
        for(int i=1;i<=C;++i) {
            for(int j=1;j<=C;++j) {
                F[i][j] = min(max(F[i][k], F[k][j]), F[i][j]);
            }
        }
    }
    for(int q=0;q<Q;++q) {
        int c1, c2;
        cin >> c1 >> c2;
        if(F[c1][c2] == INF)
            cout << "no path" << '\n';
        else
            cout << F[c1][c2] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int kase = 1;
    while(cin >> C >> S >> Q and C and S and Q) {
        cout << "Case #" << kase++ << '\n';
        solve();
        cout << '\n';
    }
    return 0;
}