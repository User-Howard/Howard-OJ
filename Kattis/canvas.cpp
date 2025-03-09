#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define int int64_t


int solve() {
    int N;
    cin >> N;
    priority_queue<int> pq;
    for(int x, i=0;i<N;++i) {
        cin >> x;
        pq.push(-x);
    }
    int answer = 0;
    while(pq.size()>1) {
        int a = -pq.top(); pq.pop();
        int b = -pq.top(); pq.pop();
        answer += a + b;
        pq.push(-a-b);
    }
    return answer;
}
signed main() {
    int T;
    cin >> T;
    while(T--) {
        cout << solve() << '\n';
    }

    return 0;
}
