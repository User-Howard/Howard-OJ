#include<iostream>
using namespace std;
const int MAXN=4;


int N;
int arr[1002];
int dp[1002][1002];
int Game(int l, int r){
    if(dp[l][r]!=INF){
        return dp[l][r];
    }
    
}
int main(){
    cout<<MAXN;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    cout<<Game(0, N-1)<<endl;
    return 0;
}
