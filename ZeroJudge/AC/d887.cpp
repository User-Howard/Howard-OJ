#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    int N;
    uint64_t DP[26][26]={0};
    fill(begin(DP[0]), end(DP[0]), 1);

    for(int i=1;i<26;i++){
        for(int j=i;j<26;j++){
            DP[i][j] = DP[i-1][j] + DP[i][j-1];
        }
    }
    while(cin>>N){
        cout<<DP[N][N]<<endl;
    }
    return 0;
}