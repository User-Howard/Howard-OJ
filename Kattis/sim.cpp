#include <iostream>
#include <list>
using namespace std;


void solve() {
    string Input;
    list<char> S;
    getline(cin, Input);
    auto it = S.begin();
    for(char c: Input) {
        if(c=='<') {
            if(it!=S.begin()) {
                it = S.erase(--it);
            }
        } else if(c=='[') {
            it = S.begin();
        } else if(c==']') {
            it = S.end();
        } else {
            it = S.insert(it, c);
            it++;
        }
    }
    string out;
    for(char c: S) {
        cout << c;
    }
    cout << '\n';
}
int main() {
    int T;
    cin >> T;
    getchar();
    while(T--) {
        solve();
    }
    return 0;
}