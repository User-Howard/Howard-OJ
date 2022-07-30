#include <iostream>
#include <vector>
using namespace std;


string solve() {
    int N, M;
    cin >> N >> M;
    vector<int> vec((M+1)/2);
    for(int r, i=0;i<N;++i) {
        cin >> r;
        ++vec[min(r, M+1-r)-1];
    }
    string S(M, 'B');
    for(int i=0;i<(M+1)/2;++i) {
        if(vec[i] > 0)
            S[i] = 'A';
        if(vec[i] > 1)
            S[M-1-i] = 'A';
    }
    return S;
}
int main(){
    int T;
    cin >> T;
    while(T--)
        cout << solve() << '\n';
    return 0;
}