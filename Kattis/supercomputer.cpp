#pragma GCC optimzize("Ofast,no-stack-protector")
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
const int MAX_N = 5e6+10;

array<int, MAX_N> BIT;
int query(int x) {
    x+=2;
    int ans=0;
    for(;x>0;x-=lowbit(x)) {
        ans += BIT[x];
    }
    return ans;
}
void update(int x, int v) {
    x+=2;
    for(;x<MAX_N;x+=lowbit(x)) {
        BIT[x] += v;
    }
}
signed main(){
    quick
    int N, M;
    cin >> N >> M;
    vector<bool> Nums(N+1, false);
    while(M--) {
        char op;
        int a, b;
        cin >> op;
        if(op=='F') {
            cin >> a;
            if(Nums[a]) {
                update(a, -1);
                Nums[a] = false;
            } else {
                update(a, 1);
                Nums[a] = true;
            }
        } else {
            cin >> a >> b;
            cout << query(b)-query(a-1) << '\n';
        }
    }
    return 0;
}