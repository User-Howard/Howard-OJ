#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;


const int MAX_N = 1e6;
int T, N, M;
int checkteam[MAX_N];
queue<int> line;
queue<int> member[1002];
void init(){
    while(!line.empty())
        line.pop();
    for(int i=0;i<1002;++i){
        while(!member[i].empty())
            member[i].pop();
    }
}
void solve(){
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, a;
    cin >> N;
    fill(checkteam, checkteam+1000000, 0);
    for(int i=1;i<=N;++i){
        cin >> m;
        for(int j=0;j<m;++j){
            cin >> a;
            checkteam[a] = i;
        }
    }
    // for(int i=1;i<=8;++i)
    //     cout << checkteam[i] << '\t';
    // cout << '\n';
    cin >> M;
    while(M--){
        string s;
        cin >> s;
        if(s == "ENQUEUE"){
            cin >> a;
            if(member[checkteam[a]].size() == 0 or checkteam[a] == 0)
                line.push(checkteam[a]);
            member[checkteam[a]].push(a);
        }
        else{
            // cout << "TEAM " << line.front() << '\n';
            cout << member[line.front()].front() << '\n';
            member[line.front()].pop();
            if(member[line.front()].size() == 0 or line.front() == 0)
                line.pop();
        }
    }
}
int main(){
    cin >> T;
    for(int k=1;k<=T;++k){
        cout << "Line #" << k << '\n';
        solve();
    }
    return 0;
}