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

bool solve() {
    int N, M;
    string A, B;
    cin >> N >> M >> A >> B;
    reverse(all(A));
    reverse(all(B));
    if (A.substr(0, M-1) != B.substr(0, M-1)) {
        return false;
    }
    else {
        for(int i=M-1;i<N;++i) {
            if(A[i] == B[M-1])
                return true;
        }
        return false;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
        cout << (solve()? "YES":"NO") << '\n';
    return 0;
}