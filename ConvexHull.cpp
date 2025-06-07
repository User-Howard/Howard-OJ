#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define int int64_t

typedef pair<int, int> pii;

int N;

pii operator-(pii a, pii b) {
    return {a.first-b.first, a.second-b.second};
}
pii operator+(pii a, pii b) {
    return {a.first+b.first, a.second+b.second};
}
pii operator*(pii a, int x) {
    return {a.first*x, a.second*x};
}
int operator^(pii a, pii b) {
    return a.first*b.second - a.second*b.first;
}
int ori(pii o, pii a, pii b) {
    return (a-o)^(b-o);
}
ostream& operator<<(ostream& os, const pii& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
double length(pii a) {
    return sqrt(a.first*a.first+a.second*a.second);
}
vector<pii> solve(vector<pii>& Points) {
    sort(Points.begin(), Points.end());
    Points.erase(unique(Points.begin(), Points.end()), Points.end());
    N = size(Points);

    vector<pii> V;
    for(int t=0;t<2;++t) {
        int sz = size(V);
        for(auto point: Points) {
            while(size(V)-sz>=2 and ori(V[size(V)-2], V[size(V)-1], point)<=0)
                V.pop_back();
            V.push_back(point);
        }
        V.pop_back();
        reverse(Points.begin(), Points.end());
    }
    return V;
}
signed main() {
    while(cin >> N and N) {
        vector<pii> Points(N);
        for(auto &i: Points) cin >> i.first >> i.second;
        auto convexHull = solve(Points);

        pii psum;
        pii lastO(Points.front());
        for(auto point: Points) {
            psum = psum + point - Points.front();
        }
        for(int i=0;i<size(convexHull);++i) {
            auto &p1 = convexHull[i];
            auto &p2 = convexHull[(i+1)%size(convexHull)];
            psum = psum + (lastO-p1)*size(Points);
            lastO = p1;

            double ans = abs(psum^(p2-p1)); ans /= length(p2-p1);
            cout << p1 << ' ' << p2 << '\n';
            cout << ans << "\n\n";
        }
    }
    return 0;
}
