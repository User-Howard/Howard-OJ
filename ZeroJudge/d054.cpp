#include<iostream>
using namespace std;


int main(){
    int N, n;
    uint64_t dp[45]={1, 1, 5};
    for(int i=3;i<45;i++){
        dp[i] = dp[i-1]*1 + dp[i-2]*4 + dp[i-3]*2;
    }
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>n;
        cout<<dp[n]<<endl;
    }

    return 0;
}