#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> T(N), S(N);
    int cnt = 0, mx = 0, mxt;
    for(int i=0;i<N;++i) {
        cin >> T[i] >> S[i];
        if(S[i] == -1)
            cnt ++;
        if(S[i] > mx) {
            mx = S[i];
            mxt = i;
        }
    }
    int score = max(mx - N - 2*cnt, 0);
    cout << score << ' ' << T[mxt] << '\n';
    return 0;
}