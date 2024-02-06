#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


const int MAX_N = 2e5 + 5;
int N, X;
int P[MAX_N];
int main() {
    cin >> N >> X;
    for(int i=0;i<N;++i) cin >> P[i];
    sort(P, P+N, greater<int>());
    int a=0, b=N-1, answer=0;
    while(a<=b) {
        if(P[a]+P[b] > X) {
            ++a;
        } else {
            ++a, --b;
        }
        ++answer;
    }
    cout << answer;
    return 0;
}