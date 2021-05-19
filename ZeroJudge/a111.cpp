#include<iostream>
using namespace std;

int main(){
    int N;
    uint32_t dp[102]={0, 1};
    for(int i=2;i<101;i++){
        dp[i] = dp[i-1] + i*i;
    }
    while(cin>>N && N){
        cout<<dp[N]<<endl;
    }
    return 0;
}