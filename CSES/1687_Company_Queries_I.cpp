#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


const int MAX_N = 2e5 + 5;
int dp[MAX_N][20]={};
int main() {
    int N, Q;
    cin >> N >> Q;
    for(int i=2;i<=N;++i)
        cin >> dp[i][0];
    for(int i=1;i<20;++i) {
        for(int j=1;j<=N;++j) {
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
    while(Q--) {
        int a, b;
        cin >> a >> b;
        for(int i=0;i<20;++i) {
            if(b & (1<<i)) a = dp[a][i];
        }
        if(a) cout << a << '\n';
        else cout << "-1\n";
    }
    
    
    return 0;
}