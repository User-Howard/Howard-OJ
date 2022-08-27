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

int N, M;
int solve() {
    cin >> N >> M;
    vi A(M);
    vi H(M), J(M);
    vpii RS;
    for(int i=0;i<M;++i)
        cin >> A[i];
    if(M != 1) {
        sort(all(A));
        for(int i=0;i<M;++i) {
            int ra = A[i], rb = A[(i+1)%M];
            H[i] = (rb - ra + N)%N - 1;
            RS.pb(mp(H[i], i));
        }
    } else {
        if(N > 2)
            return 2;
        else
            return 1;
    }
    
    // for(int i=0;i<H.size();++i)
    //     cout << H[i] << ' ';
    // cout << '\n';
    J.resize(H.size());
    sort(all(RS));
    reverse(all(RS));
    for(int i=0;i<RS.size();++i) {
        int j = RS[i].se;
        for(int t=1;t<=2;++t) {
            J[j] = t;
            if(H[j] == 1)
                J[j] = 2;
            for(int k=0;k<H.size();++k) {
                H[k] -= 2 - J[k];
                if(H[k] < 0)
                    H[k] = 0;
            }
            
            // for(int re=0;re<H.size();++re) {
            //     cout << H[re] << '\t';
            // }
            // cout << '\n';
        }
    }
    int ans = N;
    for(int i=0;i<H.size();++i)
        ans -= H[i];
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cout << solve() << '\n';
    }
    return 0;
}