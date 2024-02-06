#include <iostream>
#include <set>
using namespace std;


int main() {
    int N;
    set<int> ans;
    cin >> N;
    for(int i=0;i<N;++i) {
        int x;
        cin >> x;
        ans.insert(x);
    }
    cout << ans.size() << '\n';
    return 0;
}