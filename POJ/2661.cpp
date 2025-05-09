#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int N;
    while(cin >> N and N) {
        double a = log10(2.0)*pow(2.0, (N-1940)/10);
        int ans = 0;
        double f = 0;
        while(f<a) {
            f += log10(1.0*(++ans)*1.0);
        }
        cout << ans-1 << '\n';
    }
    return 0;
}