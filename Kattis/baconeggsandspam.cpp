#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<string> splitString(string S) {
    vector<string> R;
    R.push_back("");
    for(char c: S) {
        if(c==' ') {
            R.push_back("");
        } else {
            R.back() += c;
        }
    }
    return R;
}
int N;
void solve() {
    string S;
    getchar();
    map<string, vector<string> > MP;
    for(int _=0;_<N;++_) {
        getline(cin, S);
        auto V = splitString(S);
        for(int i=1;i<V.size();++i) {
            MP[V[i]].push_back(V[0]);
        }
    }
    for(auto i: MP) {
        cout << i.first;
        sort(i.second.begin(), i.second.end());
        for(auto j: i.second) {
            cout << ' ' << j;
        }
        cout << '\n';
    }
}
int main() {
    bool f = 0;
    while(cin >> N) {
        if(!N) break;
        if(f) cout << '\n';
        f=1;
        solve();
    }
    return 0;
}