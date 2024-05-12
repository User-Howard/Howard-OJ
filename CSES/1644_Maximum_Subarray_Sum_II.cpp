#include <iostream>
#include <algorithm>
using namespace std;


const int MAX_N = 2e5 + 10;
const int64_t INF = 1e18;
int N, A, B;
int X[MAX_N];
int64_t prefix[MAX_N];
int64_t MIN[MAX_N<<2];
void update(int pos, int64_t x, int u=1, int l=0, int r=MAX_N) {
    MIN[u] = min(MIN[u], x);
    if(l==r) return;
    const int mid = (l+r) / 2;
    if(pos<=mid) update(pos, x, 2*u, l, mid);
    else       update(pos, x, 2*u+1, mid+1, r);

}
int64_t query(int posl, int posr, int u=1, int ul=0, int ur=MAX_N) {
    if(posl<=ul and ur<=posr) return MIN[u];
    const int mid = (ul + ur) / 2;
    int64_t answer = 1e18 + 10;
    if(posl<=mid) answer = min(answer, query(posl, posr, 2*u, ul, mid));
    if(mid+1<=posr) answer = min(answer, query(posl, posr, 2*u+1, mid+1, ur));
    return answer;
}
int main() {
    cin >> N >> A >> B;
    fill(MIN, MIN+4*MAX_N, INF);
    for(int i=1;i<=N;++i) {
        static int64_t cnt = 0;
        cin >> X[i];
        cnt += X[i];
        prefix[i] = cnt;
        update(i, prefix[i]);
    }
    update(0, 0LL);
    int64_t answer = -INF;
    for(int i=A;i<=N;++i) {
        answer = max(answer, prefix[i] - query(max(0, i-B), i-A));
    }
    cout << answer << '\n';
    return 0;
}
