#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    int A[(int)1e6+5] = {0};
    cin >> N;
    for(int i=1;i<=N;++i) {
        cin >> A[i];
    }
    sort(A+1, A+N+1);

    int answer = N;
    for(int i=1;i<=N;++i) {
        answer = min(answer, N-i+A[i]);
    }
    cout << answer << '\n';
    return 0;
}