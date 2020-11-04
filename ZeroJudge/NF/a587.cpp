#include<iostream>
#include<algorithm>
using namespace std;
#define INF (int )0x3f3f3f3f

int N, V;
struct E{
    int W, V;
} arr[102];
int dp[102];
int f(int x){
    if(x<=0)
        return 0;
        /*
    if(dp[x] > 0)
        return dp[x];
        */
    int q = -INF;
    for(int i=0;i<N;i++){
        q = max(q, f(x - arr[i].W) + arr[i].V);
    }
    dp[x] = q;
    return q;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i].W>>arr[i].V;
    }
    cin>>V;
    cout<<f(V)<<'\n';
    for(int i=1;i<=V;i++){
        cout<<dp[i]<<' ';
    }
}
