//
//  3. 線段覆蓋長度.cpp
//  APCS
//
//  Created by 吳浩瑋 on 2022/9/27.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

istream& operator>>(istream& stream,  pii& p) {
    stream >> p.fi >> p.se;
    return stream;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vpii Lines(N);
    for(pii &i : Lines) cin >> i;
    sort(all(Lines));
    int s = 0, e = 0, ans = 0;
    for(pii i : Lines) {
        if(i.fi <= e) {
            e = max(i.se, e);
        } else {
            ans += e - s;
            s = i.fi;
            e = i.se;
        }
    }
    ans += e - s;
    cout << ans << '\n';

    return 0;
}