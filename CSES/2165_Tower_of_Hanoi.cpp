#include <iostream>
#include <cmath>
using namespace std;

void Hanoi(int n, int a=1, int b=2, int c=3) {
    if(n == 1) {
        cout << a << ' ' << c << '\n';
    } else {
        Hanoi(n-1, a, c, b);
        Hanoi(1, a, b, c);
        Hanoi(n-1, b, a, c);
    }
}
int main() {
    int N;
    cin >> N;
    cout << pow(2, N) - 1 << '\n';
    Hanoi(N);
    return 0;
}