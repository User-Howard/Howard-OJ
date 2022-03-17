#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


const int INF = 0x3f3f3f3f;
const int MAX_N = 1e5 + 2;
struct Box{
    int max_cnt = 0, delay_cnt = 0;
    vector<int> child;
}box[MAX_N];
int N;
int search(int u, int breakpoint){
    for(int i:box[u].child){
        if(i != breakpoint){
            int result = search(i, u);
            box[u].delay_cnt += result;
            box[u].max_cnt = max(box[u].max_cnt, result);
        }
    }
    box[u].max_cnt = max(box[u].max_cnt, N - 1 - box[u].delay_cnt);
    return box[u].delay_cnt + 1;
}
void solve(){
    cin >> N;
    for(int i=0;i<N;++i){
        box[i].max_cnt = box[i].delay_cnt = 0;
        box[i].child.clear();
    }
    for(int i=1;i<N;++i){
        int x, y;
        cin >> x >> y;
        box[x].child.push_back(y);
        box[y].child.push_back(x);
    }
    search(0, 0);
    int ans = 0;
    for(int i=1;i<N;++i){
        if(box[i].max_cnt < box[ans].max_cnt)
            ans = i;
    }
    cout << ans << '\n';
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