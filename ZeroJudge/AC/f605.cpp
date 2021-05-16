#include<iostream>
#include<cmath>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, D;
    int count = 0, ans = 0;
    cin >> N >> D;
    while (N--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (max(a, max(b, c)) - min(a, min(b, c)) >= D) {
            ans += (a + b + c) / 3;
            ++count;
        }
    }
    cout << count << ' ' << ans << endl;
    return 0;
}