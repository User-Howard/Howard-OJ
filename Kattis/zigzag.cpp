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

signed main(){
    quick
    int N;
    cin >> N;
    vector<int> ans;
    while(N) {
        if(N<=25) {
            ans.push_back(N);
            N = 0;
        } else {
            int r = (N<50) ? N%50 : 50;
            ans.push_back((r+1)/2);
            ans.push_back(r-(r+1)/2);
            N -= r;
        }
    }
    if(size(ans)%2==0) {
        if(ans[size(ans)-1]!=ans[size(ans)-2]) {
            ans[size(ans)-1]++;
            ans[1]--;
        }
    }
    cout << 'a';
    if(size(ans)%2) {
        if(size(ans)>=3) {
            while(ans.back()+2<=25) {
                ans[0]--;
                ans[1]--;
                ans.back()+=2;
            }
        }
        for(int i=0;i<size(ans);i+=2) {
            cout << char('a'+ans[i]);
            if(i+1<size(ans)) cout << char('a'+ans[i]-ans[i+1]);
        }
    } else {
        for(int i=0;i<size(ans)/2;++i) {
            int t = size(ans)/2-i-1;
            cout << char('a'+ans[2*t]);
            cout << char('a'+ans[2*t]-ans[2*t+1]);
        }
    }
    cout << '\n';
    // for(auto i: ans) cerr << i << ' ';
    return 0;
}
/*
77
25 + 25 + 25 + 2
14 14 25 24
25 50
*/