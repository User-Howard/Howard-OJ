#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int N;
int Nums[1005];
int main() {
    cin >> N;
    for(int i=0;i<N;++i) {
        cin >> Nums[i];
    }
    set<int> st[2];
    st[0].insert(0);
    for(int i=0;i<N;++i) {
        st[(i+1)%2].insert(st[(i)%2].begin(), st[(i)%2].end());
        for(int num: st[(i)%2]) {
            st[(i+1)%2].insert(num+Nums[i]);
        }
    }
    st[(N)%2].erase(0);
    cout << st[(N)%2].size() << '\n';
    for(int i: st[(N)%2]) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}
