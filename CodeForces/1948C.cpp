#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


int N;
const int MAX_N = 2e5 + 5;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
string T[2];
bool walked[2][MAX_N];
void init() {
    memset(walked[0], 0, sizeof(walked[0]));
    memset(walked[1], 0, sizeof(walked[1]));
}
bool walk(int x, int y) {
    if(walked[x][y]) return false;
    walked[x][y] = true;
    if((x==1 and y==N-2) or (x==0 and y==N-1) or (x==1 and y==N-1)) return true;
    
    bool q = false;
    if(T[1-x][y] == '>' and y<N-1)
        q |= walk(1-x, y+1);
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