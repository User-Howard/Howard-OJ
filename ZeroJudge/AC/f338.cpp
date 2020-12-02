#include<iostream>
#include<cmath>
using namespace std;


int N;
int X, Y, L, R;
bool solve(){
    int x, y, l;
    cin>>x>>y>>l;
    if(l<=L and hypot(abs(X-x), abs(Y-y))<=R)
        return 1;
    else
        return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ans=0;
    cin>>X>>Y>>L>>R>>N;
    while(N--){
        ans+=solve();
    }
    cout<<ans<<endl;
    return 0;
}
