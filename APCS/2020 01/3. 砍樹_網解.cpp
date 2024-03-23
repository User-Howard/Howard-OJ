#include <iostream>
#include <queue>
#include <vector>
using namespace std;


const int INF = 0x3f3f3f3f;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, L;
    cin >> N >> L;
    vector<int> C(N+2), H(N+2), nxt(N+2), pre(N+2);
    C[0] = 0, C[N+1] = L;
    for(int i=1;i<=N;++i) cin >> C[i];
    for(int i=1;i<=N;++i) cin >> H[i];
    for(int i=0;i<=N;++i) nxt[i] = i+1;
    for(int i=0;i<=N;++i) pre[i+1] = i;
    
    queue<int> q;
    int cnt = 0, max_tree = 0;
    int pointer = 1;
    while(pointer != N+1) {
        if((pointer!=0 and pointer!=N+1) and max(C[pointer]-C[pre[pointer]], C[nxt[pointer]]-C[pointer]) >= H[pointer]) {
            // cerr << pointer << '\t' << "CUT\n";
            max_tree = max(max_tree, H[pointer]);
            nxt[pre[pointer]] = nxt[pointer];
            pre[nxt[pointer]] = pre[pointer];
            pointer = pre[pointer];
            cnt++;
        }
        else {
            // cerr << pointer << '\t' << "pass\n";
            pointer = nxt[pointer];
        }
    }


    cout << cnt << '\n' << max_tree << '\n';
    return 0;
}