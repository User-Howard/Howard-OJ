#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;


const int INF = 0x3f3f3f3f;
typedef pair<int, int> Point;
#define x first
#define y second
Point operator+(Point a, Point b) {
    return Point(a.x + b.x, a.y + b.y);
}
Point operator-(Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
}
double operator*(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}
double operator^(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}
bool cmp(Point &a, Point &b) {
    return a.x==b.x ? a.y < b.y : a.x < b.x;
}
int main() {
    int N;
    cin >> N;
    vector<Point> Points(N);
    for(Point &i: Points) cin >> i.x >> i.y;
    unordered_map<int64_t, int> rv;
    for(int i=0;i<N;++i) {
        rv[((int64_t)Points[i].x<<12) + Points[i].y] = i;
    }
    sort(Points.begin(), Points.end(), cmp);
    vector<int> cont(N);
    for(int i=0;i<N;++i) {
        cont[i] = rv[((int64_t)Points[i].x<<12) + Points[i].y];
    }
    vector<Point> V;
    for(int c=0;c<2;++c) {
        int T = V.size();
        for(Point p: Points) {
            while(V.size() - T >= 2 and ((V[V.size()-1] - V[V.size()-2])^(p - V[V.size()-2])) <= 0) {
                V.pop_back();
            }
            V.push_back(p);
        }
        V.pop_back();
        reverse(Points.begin(), Points.end());
    }
    pair<int64_t, pair<int, int> > ans = make_pair(-1, make_pair(INF, INF));
    for(int i=0;i<V.size();++i) {
        for(int j=i+1;j<V.size();++j) {
            Point t = V[j] - V[i];
            int64_t d = t.x * t.x + t.y * t.y;
            int a = cont[i], b = cont[j];
            if(a > b)
                swap(a, b);
            if(ans.first < d) {
                ans.first = d;
                ans.second = make_pair(a, b);
            } else if(ans.first == d){
                ans.second = min(ans.second, make_pair(a, b));
            }
        }
    }
    cout << ans.second.first << ' ' << ans.second.second << '\n';
    return 0;
}