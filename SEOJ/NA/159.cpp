#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T, N, M;
    cin >> T;
    while(T--){
        cin >> N >> M;
        vector<int> C(N), K(N);
        for(int i=0;i<N;++i)
            cin >> C[i] >> K[i];
        vector<bool> dp(M+1);
        dp[0] = true;
        for(int i=0;i<N;++i){
            for(int j=M;j>=0;--j){
                for(int k=K[i];k>0;--k){
                    if(j-C[i] >= 0)
                        dp[j] = max(dp[j], dp[j-C[i]]);
                }
            }
        }
        cout << (dp[M]? "Yes":"No") << '\n';
    }
    return 0;
}
