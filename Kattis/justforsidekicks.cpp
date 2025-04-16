#pragma GCC optimzize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
#include <set>
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
const int MAX_N = 5e6+10;
int V[6];
map<int, int> BIT[MAX_N];
int query(int x) {
    x+=2;
    int ans=0;
    for(;x>0;x-=lowbit(x)) {
        for(int i=0;i<6;++i) {
            ans += V[i]*BIT[x][i];
        }
    }
    return ans;
}
void update(int x, int before, int after) {
    x+=2;
    for(;x<MAX_N;x+=lowbit(x)) {
        BIT[x][before]--;
        BIT[x][after]++;
    }
}
signed main(){
    quick
    int N, Q;
    cin >> N >> Q;
    for(int i=0;i<6;++i) cin >> V[i];
    vector<int> Nums(N+1, false);
    string S;
    cin >> S;
    for(int i=0;i<N;++i) {
        Nums[i+1] = S[i]-'1';
        update(i+1, 7, Nums[i+1]);
    }
    while(Q--) {
        int op;
        cin >> op;
        if(op==1) {
            int k, p;
            cin >> k >> p; p--;
            update(k, Nums[k], p);
            Nums[k]=p;
        } else if(op==2) {
            int p, v;
            cin >> p >> v; p--;
            V[p] = v;
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(r) - query(l-1) << '\n';
        }
    }
    return 0;
}