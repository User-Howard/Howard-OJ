#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


const int MAX_N = 1005;
const int MAX_X = 100005;
int N, X;
int H[MAX_N], S[MAX_N];
int main() {
    cin >> N >> X;
    for(int i=0;i<N;++i)
        cin >> H[i];
    for(int i=0;i<N;++i)
        cin >> S[i];

    vector<int> dp(X+1, -1);
    dp[0] = 0;
    for(int i=0;i<N;++i) {
        for(int j=X;j>=H[i];--j) {
            if(dp[j-H[i]] != -1) {
                dp[j] = max(dp[j], dp[j-H[i]] + S[i]);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}
