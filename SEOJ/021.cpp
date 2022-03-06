#include <iostream>
using namespace std;


int N, M;
struct E{
    int prv, nxt;
}racecar[(int)1e5+2];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<=N;++i){
        racecar[i].prv = i-1;
        racecar[i].nxt = i+1;        
    }
    cin >> M;
    int t, x;
    while(M--){
        cin >> t >> x;
        if(t==0){
            racecar[racecar[x].nxt].prv = racecar[x].prv;
            racecar[racecar[x].prv].nxt = racecar[x].nxt;
        }
        else{
            if(racecar[x].prv != 0){
                int a = racecar[racecar[x].prv].prv;
                int b = racecar[x].nxt;
                int bef = racecar[x].prv;
                racecar[a].nxt = x;
                racecar[bef].nxt = b;racecar[bef].prv = x;
                racecar[x].nxt = bef;racecar[x].prv = a;
                racecar[b].prv = bef;
            }
        }
    }
    int pointer = 0;
    while(true){
        pointer = racecar[pointer].nxt;
        if(pointer == N+1)
            break;
        cout << pointer;
        if(racecar[pointer].nxt != N+1)
            cout << ' ';
    }
    cout << '\n';
    return 0;
}