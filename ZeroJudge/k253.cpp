#include <iostream>
using namespace std;


int main() {
    int T, S, P;
    cin >> T >> S >> P;
    int r = T;
    int ans = 0;
    while(S--) {
        if(0.8*T <= r) {
            ans += P*0.5;
        } else if(0.6*T <= r) {
            ans += P*0.6;
        } else if(0.4*T <= r) {
            ans += P*0.8;
        } else if(0.2*T <= r) {
            ans += P*0.9;
        } else {
            break;
        }
        r--;
    }
    cout << ans << '\n';
    return 0;
}
