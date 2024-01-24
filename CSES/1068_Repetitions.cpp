#include <iostream>
using namespace std;


int main() {
    string S;
    cin>>S;
    int ans = 1, r = 1;
    char t = S[0];
    for(int i = 1;i<S.size();++i) {
        if(S[i]==t) {
            ans = max(ans, ++r);
        }
        else {
            t = S[i];
            r = 1;
        }
    }
    cout<<ans<<'\n';
}