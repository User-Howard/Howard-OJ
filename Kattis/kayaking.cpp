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

int B, N, E;
int S[3];
int Speed[50000+10];
int m;
bool solvable(int x) {
    int ta=B, tb=N, tc=E;
    if(S[1]+S[1]<S[0]+S[2]) {
    for(int i=0;i<m;++i) {
        if(ta>=2 and Speed[i]*(S[0]+S[0])>=x) {
            ta-=2;
        } else if(ta>=1 and tb>=1 and Speed[i]*(S[0]+S[1])>=x) {
            ta--;
            tb--;
        } else if(tb>=2 and Speed[i]*(S[1]+S[1])>=x) {
            tb-=2;
        } else if(ta>=1 and tc>=1 and Speed[i]*(S[0]+S[2])>=x) {
            ta--;
            tc--; 
        } else if(tb>=1 and tc>=1 and Speed[i]*(S[1]+S[2])>=x) {
            tb--;
            tc--; 
        } else if(tc>=2 and Speed[i]*(S[2]+S[2])>=x) {
            tc-=2;
        } else {
            return false;
        }
    }
    } else {
    for(int i=0;i<m;++i) {
        if(ta>=2 and Speed[i]*(S[0]+S[0])>=x) {
            ta-=2;
        } else if(ta>=1 and tb>=1 and Speed[i]*(S[0]+S[1])>=x) {
            ta--;
            tb--;
        } else if(ta>=1 and tc>=1 and Speed[i]*(S[0]+S[2])>=x) {
            ta--;
            tc--; 
        } else if(tb>=2 and Speed[i]*(S[1]+S[1])>=x) {
            tb-=2;
        } else if(tb>=1 and tc>=1 and Speed[i]*(S[1]+S[2])>=x) {
            tb--;
            tc--; 
        } else if(tc>=2 and Speed[i]*(S[2]+S[2])>=x) {
            tc-=2;
        } else {
            return false;
        }
    }
    }
    return true;
}
signed main(){
    quick
    cin >> B >> N >> E;
    for(int i=0;i<3;++i) cin >> S[i];
    m = (B+N+E)/2;
    for(int i=0;i<m;++i) {
        cin >> Speed[i];
    }
    sort(Speed, Speed+m);
    int l=0, r=2e9;
    while(r-l>1) {
        int mid=l+(r-l)/2;
        if(solvable(mid)) {
            l=mid;
        } else {
            r=mid;
        }
    }
    cout << l << '\n';
    return 0;
}