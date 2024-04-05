#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define all(x) x.begin(),x.end()

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int N;
    cin >> N;
    vector<int> G(N);
    for(int i=0;i<N;++i) {
        int x;
        cin >> x;
        G[x] = i;
    }
    int answer = 1;
    for(int i=1;i<=N;++i) {
        if(G[i] < G[i-1])
            answer ++;
    }
    cout << answer << '\n';
    return 0;
}