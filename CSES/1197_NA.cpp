#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX_N = 2505;
int dis[MAX_N];
int G[MAX_N][MAX_N];
int main() {
    int N, M;
    cin >> N >> M;

    fill(&dis[0], &dis[0]+MAX_N, INF);
    fill(&G[0][0], &G[0][0]+MAX_N*MAX_N, -1);
    for(int i=0;i<N;++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a][b] = G[b][a] = c;
    }
    
    return 0;
}
