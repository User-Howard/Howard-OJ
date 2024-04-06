#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <set>
using namespace std;
 

set<int> s;
priority_queue<pair<int, pair<int, int> > > pri;
void init() {
    s.insert(0);
    s.insert(X);
    pri.push({X, {0, X}});
}
bool available(pair<int, int> p) {
    const int &a = p.first, &b = p.second;
    return *s.upper_bound(a) == b;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int X, N;
    cin >> X >> N;
    vector<int> Nums(N);
    for(int &i: Nums) cin >> i;
    
    init();

    for(int num: Nums) {
        s.insert(num);
        while(not available(pri.top().second)) {
            int a, b, c;
            tie(a, b) = pri.top().second; pri.pop();
            c = *s.upper_bound(a);
            pri.push({c-a, {a, c}});
            pri.push({b-c, {c, b}});
        }
        cout << pri.top().first << ' ';
    }
    cout << '\n';
    return 0;
}