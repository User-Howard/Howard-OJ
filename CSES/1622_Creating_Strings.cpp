#include <iostream>
#include <set>
using namespace std;

set<string> ans;
void solve(const string A, const string B) {
    if(B.empty()) {
        ans.insert(A);
        return;
    }
    for(int i=0;i<B.size();++i) {
        solve(A+B[i], B.substr(0, i)+B.substr(i+1));
    }
}
int main() {
    string S;
    cin >> S;

    solve("", S);
    cout << ans.size() << '\n';
    for(string i: ans) cout << i << '\n';
    return 0;
}