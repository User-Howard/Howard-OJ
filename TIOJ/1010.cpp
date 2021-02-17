#include <iostream>
#include <cmath>
using namespace std;


string P, Q;
bool test(int x) {
    for (int i=0;i<x;i++) {
        if (P[i]!=Q[Q.size()-x+i])
            return false;
    }
    return true;
}
int main() {
    cin >> P >> Q;
    int ans = 0;
    for (int t = 1;t <= min(P.size(), Q.size());++t) {
        if (test(t)) {
            ans = t;
        }
    }
    cout << ans << endl;
    return 0;
}