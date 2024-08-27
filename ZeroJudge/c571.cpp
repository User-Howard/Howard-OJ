// https://oi-wiki.org/misc/cdq-divide/
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <istream>
#include <ostream>
#include <vector>
#include <set>
#include <map>
using namespace std;


struct Point {
    int a, b, c;
    int res;
    int id;
    friend istream& operator>>(istream& input, Point& obj);
    bool operator<(const Point& rhs) const {
        return a < rhs.a;
    }
    bool operator!=(const Point& rhs) const {
        return a != rhs.a || b != rhs.b || c != rhs.c;
    }
};
istream& operator>>(istream& input, Point& obj) {
    input >> obj.a >> obj.b >> obj.c;
    return input;
}
bool cmpA(const Point& lhs, const Point& rhs) {
    if(lhs.a != rhs.a) return lhs.a < rhs.a;
    if(lhs.b != rhs.b) return lhs.b < rhs.b;
    return lhs.c < rhs.c;
}
bool cmpB(const Point& lhs, const Point& rhs) {
    if(lhs.b != rhs.b) return lhs.b < rhs.b;
    return lhs.c < rhs.c;
}
struct BinaryIndexedTree {
private:
    vector<int> tree;
    int lowbit(int x) {
        return x & -x;
    }
public:
    BinaryIndexedTree(int n) : tree(n+5, 0) {}
    void add(int x, int v=1) {
        ++x;
        for(int i=x;i<tree.size();i+=lowbit(i)) {
            tree[i] += v;
        }
    }
    int query(int x) {
        ++x;
        int res = 0;
        for(int i=x;i>0;i-=lowbit(i)) {
            res += tree[i];
        }
        return res;
    }
};
vector<Point> Points;
BinaryIndexedTree bit(100005);
void cdq(int l, int r) {
    if(Points[l].a == Points[r].a) return;
    int mid = (l + r) >> 1;

    int target = -1;
    for(int i=l;i<r;++i) {
        if(Points[i].a == Points[i+1].a) continue;
        if(abs(i-mid) < abs(target-mid)) target = i;
    }
    mid = target;
    cdq(l, mid);
    cdq(mid+1, r);
    sort(next(Points.begin(), l), next(Points.begin(),mid+1), cmpB);
    sort(next(Points.begin(), mid+1), next(Points.begin(), r+1), cmpB);
    int i = l, j = mid+1;
    while(j <= r) {
        while(i <= mid && Points[i].b < Points[j].b) {
            bit.add(Points[i].c);
            ++i;
        }
        Points[j].res += bit.query(Points[j].c-1);
        ++j;
    }
    for(int k=l;k<i;++k) {
        bit.add(Points[k].c, -1);
    }
}
int main() {
    int N;
    cin >> N;
    Points.resize(N);
    for(int i=0;i<N;++i) {
        cin >> Points[i];
        Points[i].a = N - Points[i].a+1;
        Points[i].b = N - Points[i].b+1;
        Points[i].c = N - Points[i].c+1;
        Points[i].id = i;
    }
    sort(Points.begin(), Points.end(), cmpA);
    cdq(0, N-1);
    vector<int> ans(N);
    sort(Points.begin(), Points.end(), cmpA);
    for(int i=0;i<N;++i) {
        ans[Points[i].id] = Points[i].res;
    }
    for(auto i: ans) {
        cout << i << '\n';
    }
    return 0;
}
