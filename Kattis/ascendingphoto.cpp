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
    vector<int> Nums;
    for(int x, i=0;i<N;++i) {
        cin >> x;
        if(Nums.empty() or Nums.back()!=x) Nums.push_back(x);
    }
    N = size(Nums);
    set<int> st;
    st = set<int>(all(Nums));
    unordered_map<int, int> mp;
    int idx = 1;
    for(int i: st) {
        mp[i] = idx++;
    }
    for(auto &i : Nums) i = mp.at(i);

    vector<vector<int> > Counter(idx+1);
    for(int i=0;i<size(Nums);++i) {
        Counter[Nums[i]].push_back(i);
    }

    pii a1={0, INF}, a2={0, INF};
    // for(int i=0;i<size(Nums);++i) {
    //     cerr << i << ' ';
    // } cerr << '\n';
    // for(int i: Nums) cerr << i << ' ';
    // cerr << '\n';
    for(auto positions: Counter) {
        static int id = -1;
        id++;
        pii mx1=a1, mx2=a2;
        // cerr << id << ": \n";
        for(int pos: positions) {
            if(pos==size(Nums)-1 or Nums[pos]+1!=Nums[pos+1]) continue;
            pii tmp;

            // cerr << "Check\n";
            if(a1.second==INF
                or size(Counter[Nums[pos]])==1
                or (a1.second!=pos-1 and Nums[a1.second]!=Nums[pos]))
                 tmp = a1;
            else tmp = a2;
            // cerr << "tmp: (" << tmp.first << ", " << tmp.second << ") \n";
            if(tmp.second!=INF and tmp.second!=pos-1 and Nums[tmp.second]==Nums[pos]) continue;
            // cerr << ".";
            tmp.first++;
            tmp.second = pos;
            if(tmp>mx1) mx2 = mx1, mx1 = tmp;
            else if(tmp>mx2) mx2 = tmp;
            // cerr << "(" << mx1.first << ", " << mx1.second << ") ";
            // cerr << "(" << mx2.first << ", " << mx2.second << ")\n";
        }
        // cerr << "\n";
        a1 = mx1, a2 = mx2;
    }
    cout << size(Nums)-1-a1.first << '\n';

    return 0;
}