#include <iostream>
#include <string.h>
using namespace std;


const int MAX_P = 1e6;
const int INF = 0x3f3f3f3f;
int N, M;
struct E{
    int nxt;
}chain[MAX_P + 102]; // 100001 為1號商家
int last_person[102];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;++i){
        chain[MAX_P + i].nxt = INF;
        last_person[i] = MAX_P + i;
    }
    while(M--){
        string s;
        int x, y;
        cin >> s;
        if(s == "ADD"){
            cin >> x >> y;
            chain[last_person[x]].nxt = y;
            chain[y].nxt = INF;
            last_person[x] = y;
        }
        else if(s == "LEAVE"){
            cin >> x;
            if(chain[MAX_P + x].nxt == INF)
                cout << "queue " << x << " is empty!" << '\n';
            else{
                chain[MAX_P + x].nxt = chain[chain[MAX_P + x].nxt].nxt;
                if(chain[MAX_P + x].nxt == INF)
                    last_person[x] = MAX_P + x;
            }
        }
        else if(s == "JOIN"){
            cin >> x >> y;
            chain[last_person[y]].nxt = chain[MAX_P + x].nxt;
            chain[MAX_P + x].nxt = INF;
            last_person[y] = last_person[x];
            last_person[x] = MAX_P + x;
        }
    }
    for(int i=1;i<=N;++i){
        cout << "queue " << i << ":";
        if(chain[MAX_P + i].nxt == INF)
            cout << " empty" << '\n';
        else{
            int pointer = chain[MAX_P + i].nxt;
            while(pointer != INF){
                cout << ' ' << pointer;
                pointer = chain[pointer].nxt;
            }
            cout << '\n';
        }
    }
    return 0;
}