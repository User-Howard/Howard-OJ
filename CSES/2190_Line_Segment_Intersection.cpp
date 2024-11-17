#include <iostream>
using namespace std;


struct Point {
    int64_t x, y;
};
Point operator-(const Point &lhs, const Point &rhs) {
    Point ret;
    ret.x = lhs.x - rhs.x;
    ret.y = lhs.y - rhs.y;
    return ret;
}
int64_t cross(const Point &lhs, const Point &rhs) {
    return lhs.x*rhs.y - lhs.y*rhs.x;
}
int64_t dot(const Point &lhs, const Point &rhs) {
    return lhs.x*rhs.x + lhs.y*rhs.y;
}
int sign(int64_t x) {
    if(x==0) return 0;
    return (x>0) ? 1 : -1;
}
bool onseg(const Point &a, const Point &b, const Point &c) {
    if(cross(b-a, c-a)!=0) return false;
    return sign(dot(c-a, c-b)) <= 0;
}
int ori(const Point &o, const Point &a, const Point &b) {
    int64_t crossValue = cross(a-o, b-o);
    return sign(crossValue);
}
bool banana(const Point &a, const Point &b, const Point &c, const Point &d) {
    int a123 = ori(a, b, c);
    int a124 = ori(a, b, d);
    int a341 = ori(c, d, a);
    int a342 = ori(c, d, b);
    if(a123==0 and a124==0) {
        return onseg(a, b, c) or onseg(a, b, d) or onseg(c, d, a) or onseg(c, d, b);
    }
    return a123*a124<=0 and a341*a342<=0;
}
int main() {
    // freopen("in", "r", stdin);
    int T;
    cin >> T;
    while(T--) {
        static Point a, b, c, d;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        if(banana(a, b, c, d)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
