#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;


const int INF = 0x3f3f3f3f;
const int MAX_N = 1e5;
int N;
struct E{
    pair<int, int> m = {-1, -1};
    vector<int>child;
    bool gone = false;
}G[MAX_N];
void init(){
    for(int i=0;i<N;++i){
        G[i] = E{};
    }
}
pair<int, int> walk(int a){
    if(G[a].gone)
        return G[a].m;
    G[a].gone = true;
    vector<int>result;
    for(int i:G[a].child)
        result.push_back(walk(i).first+1);
    sort(result.begin(), result.end(), greater<int>());
    while(result.size()<2)
        result.push_back(0);
    G[a].m.first = result[0];
    G[a].m.second = result[1];
    return G[a].m;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> N){
        init();
        for(int i=0;i<N-1;++i){
            int a, b;
            cin >> a >> b;
            G[a].child.push_back(b);
        }
        for(int i=0;i<N;++i)
            walk(i);
        int ans = -INF;
        for(int i=0;i<N;++i){
            ans = max(G[i].m.first + G[i].m.second, ans);
        }
        cout << ans << '\n';
    }
    return 0;
}
