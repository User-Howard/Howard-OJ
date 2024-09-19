#include <iostream>
#include <algorithm>
using namespace std;


struct Point {
    int64_t x, y;
};
int64_t cross(const Point lhs, const Point rhs) {
    return 1LL*lhs.x*rhs.y - 1LL*lhs.y*rhs.x;
}
Point operator-(Point lhs, Point rhs) {
    Point ret;
    ret.x = lhs.x - rhs.x;
    ret.y = lhs.y - rhs.y;
    return ret;
}
int main() {

    int T;
    cin >> T;
    while(T--) {
        static Point a, b, c;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        
        int64_t ans = cross(b-a, c-a);
        if(ans == 0) {
            cout << "TOUCH\n";
        }
        else if(ans > 0) {
            cout << "LEFT\n";
        } else {
            cout << "RIGHT\n";
        }
    }
    return 0;
}
