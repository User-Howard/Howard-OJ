#include <iostream>
#include <cmath>
using namespace std;


int main(){
    // ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    while(N--) {
        int a, b;
        cin >> a >> b;
        uint64_t z = max(a, b);
        uint64_t ans;
        if(a<=b) {
            if(b%2) {
                ans = z*z-a+1;
            } else {
                ans = (z-1)*(z-1)+a;
            }
        } else {
            if(a%2) {
                ans = (z-1)*(z-1)+b;
            } else {
                ans = z*z-b+1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
