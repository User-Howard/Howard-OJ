#include<bits/stdc++.h>
using namespace std;

int solve(int n, int m, int k){
    /*
    n-1, m, k-1;
    */
    return (solve(n-1, m, k-1))
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, K;
    cin>>N>>M>>K;
    cout<<solve(N, M, K)<<endl;
    return 0;
}
