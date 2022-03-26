#include <iostream>
#include <vector>
#include <string>
using namespace std;



int T, N, M;
vector<int> G[(int)1e5+5];
int tag[(int)1e5+5];
void dfs(int x){
    for(int i:G)
}
int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        while(M--){
            int i, j;
            cin >> i >> j;
            G[i].push_back(j);
        }
        fill(tag, tag + N, -1);
        for(int i=0;i<N;++i){
            if(tag[i] == -1)
                dfs(i);
        }
    }
    return 0;
}