#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define all(x) x.begin(),x.end()


bool solve() {
    int N, M, P;
    cin >> N >> M >> P;
    vector<int> C(N), D(M);
    for(int &i: C) cin >> i;
    for(int &i: D) cin >> i;
    sort(all(C));
    sort(all(D));
    priority_queue<double> Q;
    for(int i: C) {
        for(int j: D) {
            Q.push(-1.0*i/j);
        }
    }
    double last_v = 1.0* C.front() / D.back();
    // cerr << last_v << '\n';
    while(not Q.empty()) {
        // cerr << -Q.top() << '\n';
        if(100.0*((-Q.top())-last_v)/last_v > P) {
            return false;
        }
        last_v = -Q.top();
        Q.pop();
    }
    return Q.empty();
}
int main() {
    cout << (solve() ? "Ride on!" : "Time to change gears!") << '\n';

    return 0;
}