//
//  1869.cpp
//  TIOJ
//
//  Created by 吳浩瑋 on 2022/9/20.
//
#include <iostream>
#include <vector>
using namespace std;
#define lowbit(x) x & -x


int N;
const int MAX_N = 1024 + 2;
void debug() {
    cout << '\n';
}
template <class T,class ... U >
void debug(T a, U ... b) {
    cout << a << ' ' , debug(b...);
}
vector<vector<int> > BIT(MAX_N, vector<int>(MAX_N));
int query(int x, int y) {
    int ret = 0;
    for(int i=x;i>0;i-=lowbit(i)) {
        for(int j=y;j>0;j-=lowbit(j)) {
            ret += BIT[i][j];
        }
    }
    // debug("query", "x", x, "y", y, "SOL: ", ret);
    return ret;
}
void modify(int x, int y, int v) {
    for(int i=x;i<N;i+=lowbit(i))
        for(int j=y;j<N;j+=lowbit(j))
            BIT[i][j] += v;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    N += 1;
    int c, x, y, z, x1, y1, x2, y2;
    while(cin >> c) {
        if(c == 1) {
            cin >> x >> y >> z;
            modify(x+1, y+1, z);
        } else {
            cin >> x1 >> y1 >> x2 >> y2;
            int answer = 0;
            answer += query(x2+1, y2+1);
            answer -= query(x1, y2+1);
            answer -= query(x2+1, y1);
            answer += query(x1, y1) ;
            cout << answer << '\n';
        }
    }
    return 0;
}
