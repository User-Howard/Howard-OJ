#include <iostream>
#include <iterator>
#include <set>
using namespace std;


const int MAX_N = 1e5 + 5;
int N, M;
int father[MAX_N];
int find_father(int x) {
    if(father[x] == x) {
        return x;
    }
    return father[x] = find_father(father[x]);
}
bool same(int x, int y) {
    return find_father(x) == find_father(y);
}
int main() {
    cin >> N >> M;
    for(int i=1;i<=N;++i) {
        father[i] = i;
    }
    set<int> s(father+1, father+1+N);
    for(int i=0;i<M;++i) {
        static int a, b;
        cin >> a >> b;
        if(!same(a, b)) {
            s.erase(find_father(a));
        }
        father[find_father(a)] = find_father(b);
    }
    cout << s.size() - 1 << '\n';
    for(auto i=s.begin();next(i)!=s.end();++i)
        cout << *i << ' ' << *next(i) << '\n';
    return 0;
}
