#include <iostream>
#include <algorithm>
using namespace std;


int solve(int N, int Q) {
    const int fi = N/2;
    const int se = N-N/2;
    if (N==1)
        return 0;
    else if (Q<=fi)
        return 2*Q-1;
    else if (N%2)
        return ((solve(se, Q-fi)-1+se)%(se))*2;
    else
        return solve(se, Q-fi)*2;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        int N, Q;
        cin >> N >> Q;
        int answer = solve(N, Q)+1;
        cout << answer << '\n';
    }
    return 0;
}
