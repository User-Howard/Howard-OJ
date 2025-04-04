#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define lowbit(x) (x&-x)

int N, M;
int BIT[1005][1005];
void update(int x, int y, int v) {
    x++, y++;
    for(int nx=x;nx<1005;nx+=lowbit(nx)) {
        for(int ny=y;ny<1005;ny+=lowbit(ny)) {
            BIT[nx][ny] += v;
        }
    }
}
int search(int x, int y) {
    x++, y++;
    int ans = 0;
    for(int nx=x;nx>0;nx-=lowbit(nx)) {
        for(int ny=y;ny>0;ny-=lowbit(ny)) {
            ans += BIT[nx][ny];
        }
    }
    return ans;
}
int main() {
    fill(&BIT[0][0], &BIT[0][0]+1005*1005, 0);
    cin >> N >> M;
    for(int i=0;i<N;++i) {
        string s;
        cin >> s;
        for(int j=0;j<N;++j) {
            if(s[j]=='*') {
                update(i+1, j+1, 1);
            }
        }
    }
    while(M--) {
        int ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        cout << search(bx, by)-search(ax-1, by)-search(bx, ay-1)+search(ax-1, ay-1) << '\n';
    }
    return 0;
}