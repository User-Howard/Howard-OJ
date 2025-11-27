#include <iostream>
#include <vector>
#include <array>
using namespace std;


array<int64_t, 21> fact;
void pre() {
    fact[0] = 1;
    for(int i=1;i<21;++i) {
        fact[i] = 1LL*fact[i-1] * i;
    }
}
int main() {
    pre();
    int N;
    int kase=0;
    cin >> N;
    while(N--) {
        string S;
        int64_t K;
        cin >> S >> K;
        int s_len = S.size();
        vector<char> vec;
        for(int i=0;i<s_len;++i) {
            vec.emplace_back('a'+i);
        }
        K--;

        string oS = "";
        for(int i=s_len-1;i>=0;--i) {
            int target = K / fact[i];
            K %= fact[i];
            oS += vec[target];
            vec.erase(vec.begin()+target);
        }

        vector<char> ans(s_len, '-');
        for(int i=0;i<s_len;++i) {
            ans[oS[i]-'a'] = S[i];
        }
        cout << "Case " << ++kase << ": ";
        for(char c: ans) cout << c;
        cout << '\n';
    }
    return 0;
}
