#include <iostream>
#include <vector>
using namespace std;


const int MAX_N = 2e5;
int N;
vector<int> G[MAX_N];
pair<int, int> solve(int x, int pre=-1) {
    pair<int, int> result{-1, x}; // length, where x is
    for(int i: G[x]) {
        if(i == pre) continue;
        auto temp = solve(i, x);
        if(result.first < temp.first) {
            result = temp;
        }
    }
    ++result.first;
    return result;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0;i<N-1;++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    cout << solve(solve(0).second).first << '\n';
    return 0;
}