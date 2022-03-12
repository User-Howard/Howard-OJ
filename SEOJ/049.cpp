#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


const int MAX_NT = 1e6 + 2;
struct Box{
    int cnt = 0;
    vector<int> child;
}box[MAX_NT];
int visited[MAX_NT];
void init(int n){
    for(int i=0;i<n;++i){
        box[i].cnt = 0;
        box[i].child.clear();
    }
    memset(visited, 0, (n+1)*sizeof(visited[0]));
}
int update(int u){
    if(visited[u]) return box[u].cnt;
    else visited[u] = 1;
    if(box[u].child.empty()) return 1;
    int sum = 0;
    for(int i:box[u].child)
        sum += update(i);
    return box[u].cnt = sum;
}
int solve(){
    int N, M;
    cin >> N >> M;
    init(N);
    for(int i=0;i<M;++i){
        int x, y;
        cin >> x >> y;
        box[x].child.push_back(y);
    }
    cout << "F" << '\n';
    for(int i=1;i<=N;++i){
        update(i);
    }
    for(int i=1;i<=N;++i)
        cout << box[i].cnt << '\n';
    return 1;
}
int main(){
    int i;
    cin >> i;
    solve();
}