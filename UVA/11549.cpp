#include <iostream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;


int N, K;
int64_t maxNumber;
int64_t square(int64_t x) {
    int64_t aux = 1LL*x*x;
    return aux/pow(10, max(int(to_string(aux).size()-N), 0));
}
int64_t next(int64_t x) {
    x = square(x);
    maxNumber = max(x, maxNumber);
    return x;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> N >> K;
        int64_t ptr1, ptr2;
        ptr1 = ptr2 = maxNumber = K;
        do
        {
            ptr1 = next(ptr1);
            ptr2 = next(next(ptr2));
        } while (ptr1 != ptr2);
        cout << maxNumber << '\n';
    }
    return 0;
}
