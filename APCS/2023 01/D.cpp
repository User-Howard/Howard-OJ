#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define all(x) (x).begin(), (x).end()
using namespace std;


typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
const int MAX_N = 1e5 + 5;

bool cmp(const pii a, const pii b) {
    return a.second < b.second;
}
int N, K;
vpii A(MAX_N);
vi machine(105, -1);
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;++i)
        cin >> A[i].first;
    for(int i=0;i<N;++i)
        cin >> A[i].second;

    sort(A.begin(), A.begin()+N, cmp);
    int ans = 0;
    for(int i=0;i<N;++i) {
        const int l = A[i].first;
        const int r = A[i].second;
        int mx = -2, mxidx = -1;
        for(int j=0;j<K;++j) {
            if(machine[j] >= l) continue;
            if(mx < machine[j]) {
                mx = machine[j];
                mxidx = j;
            }
        }
        if(mxidx == -1) continue;
        machine[mxidx] = r;
        ++ans;
    }
    cout << ans << '\n';
    return 0;
}