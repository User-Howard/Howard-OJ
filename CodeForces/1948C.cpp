#include <iostream>
#include <vector>
using namespace std;


const int MAX_N = 2e5 + 5;
int N;
string T[2];
bool walked[2][MAX_N];
void init() {
    for(int i=0;i<N;++i) {
        walked[0][i] = walked[1][i] = false;
    }
}
// bool check(int x, int y) {
//     if(dp[x][y] != -1) return dp[x][y];

//     if(T[1-x][y] == '')

// }
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool walk(int x, int y) {
    if(walked[x][y]) return false;
    walked[x][y] = true;
    if((x==1 and y==N-2) or (x==0 and y==N-1) or (x==1 and y==N-1)) return true;
    
    bool q = false;
    if(T[1-x][y] == '>' and y<N-1)
        q |= walk(1-x, y+1);
    if(y>=1 and T[x][y-1] == '<' and y>=2)
        q |= walk(x, y-2);
    if(y<N-1 and T[x][y+1]=='>' and y+1<N-1)
        q |= walk(x, y+2);
    return q;
}
bool solve() {
    cin >> N;
    init();
    for(int i=0;i<2;++i) cin >> T[i];
    return walk(0, 0);
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}