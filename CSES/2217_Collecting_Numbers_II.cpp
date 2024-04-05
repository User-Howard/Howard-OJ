#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define all(x) x.begin(),x.end()

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> G(N+2), Pos(N+2);
    G[0] = 0;
    G[N+1] = N+1;
    for(int i=1;i<=N;++i) {
        cin >> Pos[i];
        G[Pos[i]] = i;
    }
    int answer = 1;
    for(int i=1;i<=N;++i) {
        if(G[i] < G[i-1])
            answer ++;
    }
    while(M--) {
        int x, y;
        cin >> x >> y;
        if(Pos[y] < Pos[x]) swap(x, y);
        int a = Pos[x], b = Pos[y];

        if(a == b-1) {
            if(G[a] > G[b])
                answer += 1;
            else
                answer -= 1;
        }
        answer -= G[a-1] > G[a];
        answer -= G[a] > G[a+1];
        answer -= G[b-1] > G[b];
        answer -= G[b] > G[b+1];
        swap(G[Pos[x]], G[Pos[y]]);
        swap(Pos[x], Pos[y]);
        answer += G[a-1] > G[a];
        answer += G[a] > G[a+1];
        answer += G[b-1] > G[b];
        answer += G[b] > G[b+1];
        cout << answer << '\n';
    }
    return 0;
}