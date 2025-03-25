#pragma GCC optimzize("Ofast,no-stack-protector")
#include <iostream>
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
const int MAX_N = 2e5+5;
const int INF=1e18;

int N, M;
int pa[MAX_N];
int find(int x) {
    if(pa[x]==x) return x;
    else return pa[x] = find(pa[x]);
}
signed main(){
    // quick
    cin >> N >> M;
    for(int i=1;i<=N;++i) {
        pa[i] = i;
    }
    while(M--) {
        int a, b;
        cin >> a >> b;
        // cerr << a << ' ' << b << '\n';
        pa[find(b)] = find(a);
    }
    int net_head = find(1);
    int flag = true;
    for(int i=1;i<=N;++i) {
        if(find(i)!=net_head) {
            flag = false;
            cout << i << '\n';
        }
    }
    if(flag)
        cout << "Connected\n";
    return 0;
}