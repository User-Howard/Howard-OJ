#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define x first
#define y second
#define all(x) x.begin(),x.end()
typedef long double ld;
typedef long long ll;

const ll INF = 5e18;
const int MAX_N = 5e4 + 5;
int N;
pair<ll, ll> Nums[MAX_N];
ld dis(auto a, auto b) {
    ld dx = a.x-b.x;
    ld dy = a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}
void solve() {
    for(int i=0;i<N;++i)
        cin >> Nums[i].x >> Nums[i].y;
    sort(Nums, Nums+N);
    ld ans = INF;
    for(int i=0;i<N;++i) {
        for(int j=i+1;j<N;++j) {
            if(Nums[i].x + ans < Nums[j].x) break;
            ans = min(ans, dis(Nums[i], Nums[j]));
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(6);
    cout.setf(ios::fixed);
    while(cin >> N){
        solve();
    }
    return 0;
}