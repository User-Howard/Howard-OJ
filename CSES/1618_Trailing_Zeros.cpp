#include <iostream>
using namespace std;

int main() {
    int N, ans=0;
    cin >> N;
    while(N)
        ans += N = N / 5;
    cout << ans << '\n';
    return 0;
}
