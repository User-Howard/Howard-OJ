#include <iostream>
using namespace std;

string S;
bool available(int a, int b) {
    for(int i=0;i<b-a;++i) {
        if(S[a+i]=='?' or S[b+i]=='?')
            continue;
        if(S[a+i]!=S[b+i])
            return false;
    }
    return true;
}
int solve() {
    cin >> S;
    for(int i=S.size()/2;i>=0;--i) {
        for(int j=0;j+2*i<=S.size();++j) {
            if(available(j, j+i)) return i*2;
        }
    }
    return false;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        cout << solve() << '\n';
    }
    return 0;
}