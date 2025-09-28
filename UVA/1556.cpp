#include <deque>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

struct trie {
    string name;
    map<string, trie* > data;
    trie(string name): name(name) {}
    void add(deque<string>& s) {
        if(s.empty()) return;
        string dir = s.front(); s.pop_front();
        if(not data[dir]) data[dir] = new trie(dir);
        data[dir]->add(s);
    }

    void printAll(int indent=0) {
        for(auto& [dir, file]: data) {
            cout << string(indent, ' ') << dir << '\n';
            file->printAll(indent+1);
        }
    }
};
deque<string> split(string& s) {
    string token;
    deque<string> tokens;
    stringstream ss(s);

    while(getline(ss, token, '\\')) {
        tokens.push_back(token);
    }
    return tokens;
}

int N;
void solve() {
    trie Trie("/");
    string S;
    while(N--) {
        cin >> S;
        auto splited = split(S);
        Trie.add(splited);
    }
    Trie.printAll();
}
int main() {
    while(cin >> N) {
        solve();
        cout << '\n';
    }
    return 0;
}
