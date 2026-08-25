#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)

const int maxn = 5e2 + 5;
int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    vector<string> A(N);
    for(auto &i: A) cin >> i;

    vector<string> B(N, string(M, 'E'));

    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            for(char c='A';c<='D';++c) {
                if(A[i][j] == c) continue;
                if(i>0 and B[i-1][j]==c) continue;
                if(j>0 and B[i][j-1]==c) continue;
                B[i][j] = c;
                break;
            }
        }
    }
    for(const auto& i: B) cout << i << '\n';
    return 0;
}
