#include <codecvt>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define all(x) x.begin(),x.end()

struct trie {
    string name;
    map<string, trie* > mp;

    trie(string s): name(s) {}

    void add(vector<string> vec, int idx=0) {
        if(idx==vec.size()) return;
        string &S = vec[idx];
        if(mp.find(S)==mp.end()) {
            mp.insert(make_pair(S, new trie(vec[idx])));
        }
        mp[S]->add(vec, idx+1);
    }
    void printAll(int spacing=0) {
        for(const auto& [dirname, chi]: mp) {
            cout << string(spacing, ' ') << dirname << '\n';
            chi->printAll(spacing+1);
        }
    }
};
int N;
int solve() {
    trie root("&");
    while(N--) {
        string path;
        cin >> path;
        path += '\\';
        int last=0, pointer=0;
        vector<string> dirs;
        while (pointer<path.size()) {
            while(path[pointer]!='\\') pointer++;
            dirs.push_back(path.substr(last, pointer-last));
            last = pointer+1;
            pointer += 1;
        }
        root.add(dirs);
    }
    root.printAll();
    return 0;
}
int main() {
    while(cin >> N) {
        solve();
        cout << '\n';
    }
    return 0;
}
