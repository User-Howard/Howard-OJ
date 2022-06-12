#include <iostream>
#include <algorithm>
#include <iomanip>
#define Orz ios::sync_with_stdio(0),cin.tie(0)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define pdd pair<double,double>
#define int long long
#define ll long long
#define ld long double
#define N 200002
#define all(x) x.begin(),x.end()
#define INF 1e19
#define x first
#define y second
using namespace std;
int n;
pii p[N];

uint64_t dis(pii a, pii b){
    ld x = a.x-b.x, y = a.y-b.y;
    return x*x + y*y;
}

signed main(){
    Orz;
    cin >> n;
    rep(i,0,n-1)cin>>p[i].x>>p[i].y;
    sort(p,p+n);
    uint64_t d = INF;
    rep(i,0,n-1){
        rep(j,i+1,n-1){
            if(p[j].x > p[i].x + d)break;
            d = min(d, dis(p[i],p[j]));
        }
    }
    cout<<d<<endl;
    
}