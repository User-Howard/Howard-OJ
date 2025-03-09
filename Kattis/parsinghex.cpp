#include <iostream>
#include <string>
#include <vector>
using namespace std;


string S;
vector<string> Nums;
bool isHexDigit(char c) {
    return ('0'<=c and c<='9')\
        or ('a'<=c and c<='f')\
        or ('A'<=c and c<='F');
}
int toInt(char c) {
    if(c<='9') return c-'0';
    return tolower(c)-'a'+10;
}
int64_t toInt(string s) {
    int64_t answer = 0;
    for(int i=2;i<s.size();++i) {
        answer = answer*16 + toInt(s[i]);
    }
    return answer;
}
void solve() {
    for(int i=0;i<S.size()-1;++i) {
        if(S.compare(i, 2, "0x") and S.compare(i, 2, "0X")) continue;
        
        int pointer = i+2;
        while(pointer<S.size() and (pointer-i<=9) and isHexDigit(S[pointer])) pointer++;
        Nums.push_back(S.substr(i, pointer-i));
    }
}
int main() {
    while(getline(cin, S)) {
        solve();
    }
    for(auto i: Nums) {
        cout << i << ' ' << toInt(i) << '\n';
    }
    return 0;
}