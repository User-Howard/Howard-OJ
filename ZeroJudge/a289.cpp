#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;


int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a%b);
}
pair<int, int> exgcd(int a, int b) {
    if(b==0) return make_pair(1, 0);
    pair<int, int> q=exgcd(b, a%b);
    return make_pair(q.second, q.first-q.second*(a/b));
}

int main() {
    int A, B;
    while(cin >> A >> B) {
        int answer = (exgcd(A, B).first%B+B)%B;
        if(1LL*A*answer%B != 1) {
            cout << "No Inverse\n";
        }
        else {
            cout << answer << '\n';
        }
    }
    return 0;
}
