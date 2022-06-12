#include <iostream>
#include <vector>
using namespace std;

int N, M, P, K;
int holds[(int)2e4];
int visited[(int)2e4];
vector<int>G[(int)2e4];
void init(){
    for(int i=0;i<N;++i){
        G[i].clear();
        visited[i] = 0;
    }
    return;
}
bool fill_as(int x, int f){
    cout << x << '\t' << f << '\n';
    for(int i=0;i<G[x].size();++i)
        cout << G[x][i] << ' ';
    cout << '\n';
    visited[x] = f;
    for(int i=0;i<G[x].size();++i){
        if(visited[G[x][i]] == 0){
            fill_as(G[x][i], -f);
                // return 1;
        }
        else{
            // if(visited[G[x][i]]==f)
            //     return 1;
        }
    }
    return 0;
}
bool solve(){
    return 1;
}
int main(){
    cin >> N >> M;
    for(int i=0;i<M;++i)
        cin >> holds[i];
    cin >> P >> K;
    for(int kase=1;kase<=K;++kase)
        if(solve()) cout << kase << '\n';
    
    return 0;
}
