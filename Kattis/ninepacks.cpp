#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
#define int long long
#define quick ios::sync_with_stdio(0);cin.tie(0);
#define rep(x,a,b) for(int x=a;x<=b;x++)
#define repd(x,a,b) for(int x=a;x>=b;x--)
#define lowbit(x) (x&-x)
#define sz(x) (int)(x.size())
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define eb emplace_back
using namespace std;
typedef pair<int,int> pii;
void debug(){
    cout<<"\n";
}
template <class T,class ... U >
void debug(T a, U ... b){
    cout<<a<<" ",debug(b...);
}
const int INF=1e18;
const int maxn = 105;
const int maxm = 1e5+5;

signed main(){
    quick
    int A, B;
    int NumsA[maxn], NumsB[maxn];
    cin >> A;
    for(int i=0;i<A;++i) cin >> NumsA[i];
    cin >> B;
    for(int i=0;i<B;++i) cin >> NumsB[i];

    int dpA[maxm], dpB[maxm];
    fill(&dpA[0], &dpA[0]+maxm, INF);
    fill(&dpB[0], &dpB[0]+maxm, INF);
    dpA[0] = dpB[0] = 0;
    for(int i=0;i<A;++i) {
        for(int j=maxm-1;j>=NumsA[i];j--) {
            dpA[j] = min(dpA[j], dpA[j-NumsA[i]]+1);
        }
    }
    for(int i=0;i<B;++i) {
        for(int j=maxm-1;j>=NumsB[i];j--) {
            dpB[j] = min(dpB[j], dpB[j-NumsB[i]]+1);
        }
    }
    int ans = 1;
    for(int i=2;i<maxm;++i) {
        if(dpA[ans]+dpB[ans]>dpA[i]+dpB[i]) {
            ans = i;
        }
    }
    int sum = dpA[ans]+dpB[ans];
    if(sum>=INF) {
        cout << "impossible\n";
    } else {
        cout << sum << '\n';
    }
    
    return 0;
}