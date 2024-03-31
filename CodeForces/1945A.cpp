#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solve() {
    int A, B, C;
    cin >> A >> B >> C;
    if(B%3 and (B%3 + C < 3)) {
        return -1;
    }
    return A + B/3 + (C+B%3+2)/3;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        cout << solve() << '\n';
    }
    return 0;
}