#include <iostream>
#include <vector>
using namespace std;


const int INF = 0x3f3f3f3f;
int T, N;
vector<vector<int> >dp(16, vector<int>(1<<16, INF));
vector<vector<int> > G(16, vector<int>(16, INF));
int travel(int x, int s){
    if(dp[x][s] != INF)
        return dp[x][s];
    for(int i=0;i<N;++i){
        if((s & (1<<i)) != 0 and s - (1<<x) >= 0)
            dp[x][s] = min(dp[x][s], travel(i, s - (1<<x)) + G[i][x]);
        
    }
    return dp[x][s];
}
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i=0;i<N-1;++i){
            for(int j=i+1;j<N;++j){
                int d;
                cin >> d;
                G[i][j] = G[j][i] = d;
            }
        }
        for(int i=0;i<N;++i)
            dp[i][1<<i] = 0;
        cout << travel(0, (1<<N)-1) << '\n';
        
    }
	return 0;
}