#include <iostream>
#include <queue>
#include <numeric>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    queue<int> que;
    for(int i=0;i<N;++i) que.push(i+1);
    bool flag = false;
    while (not que.empty()) {
        int a = que.front(); que.pop();
        if(flag)
            cout << a << ' ';
        else 
            que.push(a);
        flag = not flag;
    }
    cout << '\n';
    return 0;
}