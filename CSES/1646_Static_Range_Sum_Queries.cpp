#include <iostream>
using namespace std;
typedef long long ll;

const int MAX_N =2e5 + 5;
int N, Q;
ll BIT[MAX_N] = {0};
void update(int pos, int x) {
    pos += 1;
    for(int i=pos;i<=MAX_N;i += i&-i) {
        BIT[i] += x;
    }
}
ll query(int pos) {
    pos += 1;
    ll res = 0;
    for(int i=pos;i>0;i -= i&-i) {
        res += BIT[i];
    }
    return res;
}
int main() {
    cin >> N >> Q;
    for(int i=1;i<=N;++i) {
        int x;
        cin >> x;
        update(i, x);
    }
    while(Q--) {
        int a, b;
        cin >> a >> b;
        cout << query(b) - query(a-1) << '\n';
    }
    return 0;
}
