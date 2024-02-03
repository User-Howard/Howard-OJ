#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;


int answer = 0;
string Board[8];
vector<pair<int, int> > queens;
bool in_board(int x, int y) {
    return 0<=x and 0<=y and x<8 and y<8;
}
bool is_available(int x, int y) {
    for(auto i: queens) {
        if(i.first == x or i.second == y) return false;
        if(i.first-i.second == x-y) return false;
        if(i.first+i.second == x+y) return false;
    }
    return true;
}
void solve(int line=0) {
    if(line == 8) {
        ++answer;
        return;
    }

    for(int i=0;i<8;++i) {
        if(Board[line][i]=='*' or !is_available(line, i)) continue;
        queens.push_back(make_pair(line, i));
        solve(line+1);
        queens.pop_back();
    }
}
int main() {
    for(string &i: Board) cin >> i;
    solve();
    cout << answer << '\n';

    return 0;
}
