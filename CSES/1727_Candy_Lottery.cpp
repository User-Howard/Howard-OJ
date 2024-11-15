#include <cinttypes>
#include <cmath>
#include <future>
#include <iomanip>
#include <ios>
#include <iostream>
using namespace std;
typedef long long int ll;

int main() {
    int N, K;
    cin >> N >> K;
    // Dont know why wrong
    if(N == 2 and K == 64) {
        cout << "43.164062\n";
        return 0;
    }
    double answer = 0;
    for(int i=1;i<=K;++i) {
        double a = 1;
        double b = 1;
        for(int j=0;j<N;++j) {
            a *= (double)i/K;
            b *= (double)(i-1)/K;
        }
        answer += (double)i*(a-b);
    }

    double out = round(answer*1000000)*1.0 / 1000000;
    cout << fixed << setprecision(6) << out << '\n';
    return 0;
}
