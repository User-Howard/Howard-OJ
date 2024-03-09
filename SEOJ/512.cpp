#include <iostream>
#include <stack>
using namespace std;

bool solve() {
    int N;
    cin >> N;
    stack<int> sta;
    for(int i=0;i<N;++i) {
        int x;
        cin >> x;
        if(x < 0) {
            if(sta.empty()) return false;
            if(sta.top() != -x) return false;
            else sta.pop();
        } else {
            sta.push(x);
        }
    }
    return sta.empty();
}
int main() {
    cout << (solve() ? "weed" : "lose light light") << '\n';

    return 0;
}