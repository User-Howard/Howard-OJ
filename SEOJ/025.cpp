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
        int s_i, s_j;
        cin >> s;
        if(s == "ADD"){
            cin >> s_i >> s_j;
            chain[last_person[s_i]].nxt = s_j;
            chain[s_j].nxt = INF;
            last_person[s_i] = s_j;
        }
        else if(s == "LEAVE"){
            cin >> s_i;
            if(chain[MAX_P + s_i].nxt == INF)
                cout << "queue " << s_i << " is empty!" << '\n';
            else{
                chain[MAX_P + s_i].nxt = chain[chain[MAX_P + s_i].nxt].nxt;
                if(chain[MAX_P + s_i].nxt == INF)
                    last_person[s_i] = MAX_P + s_i;
            }
        }
        else if(s == "JOIN"){
            cin >> s_i >> s_j;
            chain[last_person[s_j]].nxt = chain[MAX_P + s_i].nxt;
            chain[MAX_P + s_i].nxt = INF;
            last_person[s_j] = last_person[s_i];
            last_person[s_i] = MAX_P + s_i;
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