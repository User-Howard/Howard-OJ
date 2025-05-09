#include <iostream>
#include <algorithm>
#define fi first
#define se second
#define all(x) x.begin(),x.end()
using namespace std;
#define int int64_t
typedef pair<int,int> pii;


pii operator-(const pii& a, const pii& b) {
    return {a.fi-b.fi, a.se-b.se};
}
int operator^(const pii& a, const pii& b) {
    return a.fi*b.se - b.fi*a.se;
}
int ori(const pii o, const pii a, const pii b) {
    return (a-o)^(b-o);
}
int N;
void solve() {
    vector<pii> Points(N);
    for(auto &i: Points) cin >> i.first >> i.second;
    Points.erase(unique(all(Points)), Points.end());
    if(size(Points)==1) {
        cout << "1\n";
        cout << Points[0].first << ' ' << Points[0].second << '\n';
        return;
    }
    sort(all(Points));
    vector<pii> V;
    for(int t=0;t<2;++t) {
        int sz = size(V);
        for(pii point: Points) {
            while(size(V)-sz>=2 and ori(V[size(V)-2], V[size(V)-1], point)<0) {
                V.pop_back();
            }
            V.push_back(point);
        }
        V.pop_back();
        reverse(all(Points));
    }
    cout << size(V) << '\n';
    for(auto i: V) {
        cout << i.first << ' ' << i.second << '\n';
    }
}
signed main(){
    while(cin >> N and N) {
        solve();
    }
    return 0;
}