#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


const int INF = 0x3f3f3f3f;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int S, T, N, M, R;
    cin >> S >> T >> N >> M >> R;
    vector<vector<int> > A(S, vector<int>(T)), B(N, vector<int>(M));
    for(vector<int> &i:A) for(int &j:i) cin >> j;
    for(vector<int> &i:B) for(int &j:i) cin >> j;
    int s_a = 0;
    for(int i=0;i<S;++i)
        for(int j=0;j<T;++j)
            s_a += A[i][j];
        
    
    int ans = INF, cnt = 0;
    for(int i=0;i<=N-S;++i){
        for(int j=0;j<=M-T;++j){
            int diff_cnt = 0, s_b = 0;
            for(int s_i=0;s_i<S;++s_i){
                for(int s_j=0;s_j<T;++s_j){
                   if(A[s_i][s_j] != B[i+s_i][j+s_j]){
                       ++diff_cnt;
                   }
                   s_b += B[i+s_i][j+s_j];
                } 
            }
            if(diff_cnt <= R){
                ++cnt;
                ans = min(ans ,abs(s_b - s_a));
            }
        }
    }
    if(cnt == 0)
        ans = -1;
    cout << cnt << '\n' << ans << '\n';
    return 0;
}