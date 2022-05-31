#include <iostream>
#include <string.h>
using namespace std;


const int MAX_N = 1e6 + 5;
int N, M;
int G[MAX_N];
int find(int x){
    if(G[x] < 0) return x;
    return G[x] = find(G[x]);
}
int main(){
    while(cin >> N >> M){
        int answer = 1;
        fill(G, G+N, -1);
        for(int i=0;i<M;++i){
            int a, b;
            cin >> a >> b;
            a = find(a);
            b = find(b);
            if(a != b){
                G[a] += G[b];
                answer = max(answer, -G[a]);
                G[b] = a;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}
