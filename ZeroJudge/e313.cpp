#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;


int Sdiff(string S) {
    set<char> ST;
    for (char c : S)
        ST.insert(c);
    return ST.size();
}
int main() {
    int N;
    cin >> N;
    vector<pair<int, string> > Order(N);
    for(int i=0;i<N;++i) {
        string S;
        cin >> S;
        Order[i] = make_pair(Sdiff(S), S);
    }
    sort(Order.begin(), Order.end());
    cout << Order[0].second << '\n';
    return 0;
}