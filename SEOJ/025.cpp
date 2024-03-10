#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
#define f first
#define l second
#define mp make_pair


const int INF = 0x3f3f3f3f;
const int MAX_P = 1e5;
int N, M;
vector<int> store[105];
vector<int> pos(MAX_P, -1);
int main(){
    // ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    while(M--){
        string s;
        int s_i, s_j;
        cin >> s;
        if(s == "ADD"){
            cin >> s_i >> s_j;
            if(pos[s_j] != -1) {
                store[pos[s_j]].erase(find(store[pos[s_j]].begin(), store[pos[s_j]].end(), s_j));
            }
            store[s_i].push_back(s_j);
            pos[s_j] = s_i;
        }
        else if(s == "LEAVE"){
            cin >> s_i;
            if(store[s_i].empty()) {
                cout <<  "queue " << s_i << " is empty!\n";
            } else {
                pos[store[s_i][0]];
                store[s_i].erase(store[s_i].begin());
            }
        }
        else if(s == "JOIN"){
            cin >> s_i >> s_j;
            store[s_j].insert(store[s_j].end(), store[s_i].begin(), store[s_i].end());
            store[s_i].clear();
        }
    }
    for(int i=1;i<=N;++i) {
        cout << "queue " << i << ":";
        if(store[i].empty()) cout << " empty";
        else for(int i: store[i]) cout << ' ' << i;
        cout << '\n';
        // cout << store[i].f << '\t' << store[i].l << "\n";
    }
    /*
    for(int i=1;i<=N;++i) {
        cout << "queue " << i << ": ";
        if(store[i].f == -1) cout << "empty\n";
        else {
            for(int i=store[i].f;i!=store[i].l;i=nxt[i]) {
                cout << i << ' ';
            }
            cout << store[i].l << '\n';
        }
    }
    */
    
    return 0;
}