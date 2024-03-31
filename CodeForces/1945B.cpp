#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long int solve() {
    long long int A, B, C;
    cin >> A >> B >> C;

    return C/A + C/B + 2;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        cout << solve() << '\n';
    }
    return 0;
}