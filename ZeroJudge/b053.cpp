#include <iostream>
#include <vector>
using namespace std;


int N;
vector<vector<int> > mp(9, vector<int>(9, 0));
bool is_available(int x, int y, int c) {
    for(int i=0;i<N*N;++i) {
        if(mp[x][i]==c or mp[i][y]==c)
            return false;
    }
    int tx = x/N;
    int ty = y/N;
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            if(mp[tx*N+i][ty*N+j] == c)
                return false;
        }
    }
    return true;
}
bool good = false;
void solve(int r) {
    int x = r/(N*N);
    int y = r%(N*N);
    if(r == N*N*N*N) {
        good = true;
        for(int i=0;i<N*N;++i) {
            for(int j=0;j<N*N;++j) {
                cout << mp[i][j] << ' ';
            }
            cout << '\n';
        }
        return;
    }
    if(mp[x][y] == 0) {
        for(int i=1;i<=N*N;++i) {
            if(good) return;

            if(not is_available(x, y, i)) continue;

            mp[x][y] = i;
            solve(r+1);
            mp[x][y] = 0;
        }
    } else {
            solve(r+1);
    }
}
int main() {
    while(cin>>N){
        for(int i=0;i<N*N;++i) {
            for(int j=0;j<N*N;++j) {
                cin >> mp[i][j];
            }
        }
        good = false;
        solve(0);
    }
    return 0;
}