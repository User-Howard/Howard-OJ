#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define int int64_t
typedef map<pair<int, int>, int>  mpii;
typedef map<int, int> mii;
mii genMap(const vector<int>& T, int l, int r) {
    mii mp;
    mp[0] = 1;
    for(int i=l;i<r;++i) {
        vector<pair<int, int> > buffer;
        for(auto j: mp) {
            buffer.push_back(make_pair(j.first+T[i], j.second));
        }
        for(auto j: buffer) {
            mp[j.first] += j.second;
        }
    }
    return mp;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, X;
    cin >> N >> X;
    vector<int> T(N);
    for(int &i: T) cin >> i;
    sort(T.begin(), T.end());
    auto A = genMap(T, 0, N/2);
    auto B = genMap(T, N/2, N);

    int answer = 0;
    for(auto i: A) {
        auto pt = B.find(X-i.first);
        if(pt!=B.end()) {
            answer += B[X-i.first]*A[i.first];
        }
    }
    cout << answer << '\n';

    return 0;
}