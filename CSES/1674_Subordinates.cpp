#include <iostream>
#include <vector>
using namespace std;


const int MAX_N = 2e5 + 5;
int N;
vector<int> G[MAX_N];
vector<int> child(MAX_N);
int solve(int x) {
    int answer = 0;
    for(int i: G[x]) {
        answer += solve(i);
    }
    return child[x] = answer+G[x].size();
}
int main() {
    cin >> N;
    for(int i=2;i<=N;++i) {
        int a;
        cin >> a;
        G[a].push_back(i);
    }
    solve(1);
    for(int i=1;i<=N;++i) cout << child[i] << ' ';
    cout << '\n';
    return 0;
}