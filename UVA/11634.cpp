#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    int N;
    while(cin >> N and N) {
        set<int> s;
        while(s.find(N)==s.end()) {
            s.insert(N);
            N *= N;
            N /= 100;
            N %= 10000;
        }
        cout << s.size() << '\n';
    }
    return 0;
}
