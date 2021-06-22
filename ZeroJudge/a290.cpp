#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int N, M;
vector<int> G[800];
bool bfs(int x, int n){
    vector<bool>vis(N);
    queue<int>q;q.push(x);vis[x]=1;
    while(!q.empty()){
        int v=q.front();q.pop();
        if(v==n) return true;
        for(int i:G[v])
            if(!vis[i]) q.push(i), vis[i]=1;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A, B;
    while(cin >> N >> M){
        for(int i=0;i<N;i++)
            G[i].clear();
        for(int i=0, a, b;i<M;i++){
            cin >> a >> b;
            G[a-1].push_back(b-1);
        }
        cin >> A >> B;
        cout << (M!=0&&bfs(A-1, B-1) ? "Yes!!!" : "No!!!") << '\n';
    }
    return 0;
}