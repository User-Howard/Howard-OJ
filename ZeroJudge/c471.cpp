#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define W first
#define F second


bool cmp(const pii a, const pii b) {
    return a.W*b.F < a.F*b.W;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vpii V(N);
    for(pii &i: V) cin >> i.W;
    for(pii &i: V) cin >> i.F;
    sort(all(V), cmp);
    /*for(pii i: V) {
        cout << i.W << ' ' << i.F << '\n';
    }
    cout << '\n';*/
    uint64_t ans = 0;
    uint64_t pre = 0;
    for(pii i:V) {
        ans += pre*i.F;
        pre += i.W;
    }
    cout << ans << '\n';
    return 0;
}