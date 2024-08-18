#include <iostream>
#include <algorithm>
using namespace std;


int M, N, Q;
string S[105];
int getMaxSquare(int r, int c) {
    char ch = S[r][c];
    int maxLength = min(min(r, M-r-1), min(c, N-c-1));
    int answer=1;
    for(int i=1;i<=maxLength;++i) {
        for(int x=r-i;x<=r+i;++x) {
            if(S[x][c-i]!=ch or S[x][c+i]!=ch) {
                goto end;
            }
        }
        for(int y=c-i;y<=c+i;++y) {
            if(S[r-i][y]!=ch or S[r+i][y]!=ch) {
                goto end;
            }
        }
        answer = 2*i+1;
    }
end:;
    return answer;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> M >> N >> Q;
        cout << M << " " << N << " " << Q << '\n';
        for(int i=0;i<M;++i) {
            cin >> S[i];
        }
        while(Q--) {
            int r, c;
            cin >> r >> c;
            cout << getMaxSquare(r, c) << '\n';
        }
    }
    return 0;
}
