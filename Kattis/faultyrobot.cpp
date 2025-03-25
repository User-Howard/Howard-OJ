#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;


const int MAX_N = 1e3+5;
const int MAX_M = 1e4+5;
int N, M;
bool visited[MAX_N][2]={0};
vector<int> froad[MAX_N];
vector<int> road[MAX_N];
set<int> answer;
void walk(int x=1, int buggy_count=0) {
    if(visited[x][buggy_count]) return;
    visited[x][buggy_count] = true;
    for(int u: froad[x]) {
        walk(u, buggy_count);
    }
    if(froad[x].empty())
        answer.insert(x);
    if(buggy_count==0) {
        for(int u: road[x]) {
            walk(u, 1);
        }
    }
}
int main() {
    cin >> N >> M;
    for(int i=0;i<M;++i) {
        int a, b;
        cin >> a >> b;
        if(a>0) {
            road[a].push_back(b);
        } else {
            froad[-a].push_back(b);
        }
    }
    walk();
    cout << answer.size() << '\n';
    return 0;
}