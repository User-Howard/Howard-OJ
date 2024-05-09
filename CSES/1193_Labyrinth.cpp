#include <cstddef>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unistd.h>
using namespace std;


string S[1005];
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
const char movement[4] = {'U', 'L', 'R', 'D'};
struct E {
    int x, y;
    E* path;
    char way;
    E(int x_, int y_, E* prev = nullptr, char way_='-') {
        x = x_;
        y = y_;
        path = prev;
        way = way_;
    }
};
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i=1;i<=N;++i) {
        string s;
        cin >> s;
        S[i] = '#' + s + '#';
    }
    S[0] = S[N+1] = string(M+2, '#');

    queue<E> q;
    for(int i=0;i<N+2;++i) {
        for(int j=0;j<M+2;++j) {
            if(S[i][j] != 'A') continue;
            q.push(E(i, j));
            S[i][j] = '#';
        }
    }
    while(not q.empty()) {
        E hold = q.front(); q.pop();
        for(int i=0;i<4;++i) {
            int nx = hold.x+dx[i], ny = hold.y+dy[i];
            if(S[nx][ny] == '#') continue;
            if(S[nx][ny] == 'B') {
                cout << "YES\n";
                string answer = string(1, movement[i]);
                E* pointer = &hold;
                while(pointer->path) {
                    answer += pointer->way;
                    pointer = pointer->path;
                }
                reverse(answer.begin(), answer.end());
                cout << answer.size() << '\n';
                cout << answer << '\n';
                return 0;
            }
            S[nx][ny] = '#';
            q.push(E(nx, ny, new E(hold.x, hold.y, hold.path, hold.way), movement[i]));

        }
    }
    cout << "NO\n";
    return 0;
}
