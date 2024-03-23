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
    vector<bool> rec(N+2, false);
    do {
        while(q.size()) {
            int tree = q.front(); q.pop();
            max_tree = max(max_tree, H[tree]);
            cnt++;
            nxt[pre[tree]] = nxt[tree];
            pre[nxt[tree]] = pre[tree];
            for(int i: {pre[tree], nxt[tree]}) {
                if((i!=0 and i!=N+1) and max(C[i]-C[pre[i]], C[nxt[i]]-C[i]) >= H[i]) {
                    if(rec[i]) continue;
                    rec[i] = true;
                    q.push(i);
                }
            }
        }

        for(int i=1;i<=N;++i) {
            if(!rec[i] and max(C[i]-C[pre[i]], C[nxt[i]]-C[i]) >= H[i]) {
                rec[i] = true;
                q.push(i);
            }
        }
        cerr << q.size() << '\n';
    } while (q.size());
    
    

    /*
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
    */


    cout << cnt << '\n' << max_tree << '\n';
    return 0;
}