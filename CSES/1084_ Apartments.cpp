#include <iostream>
#include <vector>
using namespace std;


int N, M, K;
int answer = 0;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    vector<int> A(N), B(M);
    for(int &i: A) cin >> i;
    for(int &i: B) cin >> i;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int a=0, b=0;
    while(a<N and b<M) {
        if(abs(A[a]-B[b])<=K) {
            ++a, ++b, ++answer;
        }else {
            if(A[a]-K > B[b]) {
                ++b;
            } else {
                ++a;
            }
        }

    }
    cout << answer << '\n';
    return 0;
}