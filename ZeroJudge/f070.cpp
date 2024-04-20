#include <functional>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
using namespace std;

pair<int, int> exgcd(int a, int b) {
    if(b==0) return make_pair(1, 0);
    pair<int, int> q = exgcd(b, a%b);
    return make_pair(q.second, q.first-q.second*(a/b));
}
int main() {
    int A[3], B[3];
    for(int i=0;i<3;++i) {
        cin >> A[i] >> B[i];
    }
    int64_t mul = accumulate(A, A+3, 1LL, multiplies<int>());
    int64_t answer = 0;
    for(int i=0;i<3;++i) {
        // cerr << B[i] << '\t' << (mul/A[i]) << '\t' << (exgcd(mul/A[i], A[i]).first) << '\n';
        answer += B[i]*(mul/A[i])*(exgcd(mul/A[i], A[i]).first);
    }
    cout << (answer%mul+mul)%mul << '\n';
    return 0;
}
