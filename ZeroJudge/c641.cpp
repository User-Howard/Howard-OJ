#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define int int64_t
typedef pair<int, int> pii;

pii extgcd(int a, int b) {
    if(b==0) return {1, 0};
    auto result = extgcd(b, a%b);
    return {result.second, result.first-result.second*(a/b)};
}
signed main() {
    vector<int> K(3);
    vector<int> P(3);
    while (cin >> P[0] >> P[1] >> P[2] >> K[0] >> K[1] >> K[2]) {
        int U = 1;
        for(int i: P) U *= i;
        int result = 0;
        for(int i=0;i<3;++i) {
            result += (U/P[i])*extgcd(U/P[i], P[i]).first*K[i];
            result = (result%U+U)%U;
        }
        for(int i: P) {
            if(result<i) result += U;
        }
        cout << result << '\n';
    }

    return 0;
}
