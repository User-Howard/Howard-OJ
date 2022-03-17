#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


const int MAX_N = 1e5 + 2;
struct Box{
    int cnt = 0;
    vector<int> child;
}box[MAX_N];
bool visited[MAX_N];
void init(int n){
    for(int i=0;i<=n;++i){
        box[i].cnt = -1;
        box[i].child.clear();
    }
    memset(visited, false, (n+1)*sizeof(visited[0]));
}
int update(int u){
    if(visited[u]) return box[u].cnt;
    else visited[u] = true;

    int sum = 0;
    for(int i:box[u].child)
        sum += update(i);
    return box[u].cnt = sum + 1;
}
void solve(){
    int N, M, Q;
    cin >> N >> M;
    init(N);
    while(M--){
        int x, y;
        cin >> x >> y;
        box[x].child.push_back(y);
    }
    cin >> Q;
    while(Q--){
        int i;
        cin >> i;
        cout << update(i) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}