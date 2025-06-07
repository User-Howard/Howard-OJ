#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;
#define all(x) x.begin(),x.end()
#define lowbit(x) (x&-x)


int n;
int L, U, R, D;
struct Line {
    int ax, ay, bx, by;
};
class BIT {
    vector<int> data;
    int _size;
public:
    BIT(int size) {
        size += 10;
        data.resize(size);
        _size = size;
    }
    int query(int pos) {
        pos += 2;
        int ans(0);
        for(;pos>0;pos-=lowbit(pos)) {
            ans += data[pos];
        }
        return ans;
    }
    void update(int pos, int val=1) {
        // cerr << "Insert "  << pos << '\n';
        pos += 2;
        for(;pos<_size;pos+=lowbit(pos)) {
            data[pos] += val;
        }
    }
};
int main() {
    cin >> n >> L >> U >> R >> D;
    vector<Line> Nodes(n);
    set<int> st;
    for(int i=0;i<n;++i) {
        int ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        if(ay==by) {
            if(ax>bx) {
                swap(ax, bx);
            }
        }
        else if(ay>by) {
            swap(ax, bx);
            swap(ay, by);
        }
        st.insert({ax, ay, bx, by});
        Nodes[i] = {ax, ay, bx, by};
    }
    st.insert({L, U, R, D});
    unordered_map<int, int> mp;
    for(auto i: st) {
        static int idx = 1;
        mp[i] = idx++;
    }
    for(int i=0;i<n;++i) {
        auto [ax, ay, bx, by] = Nodes[i];
        Nodes[i] = {mp[ax], mp[ay], mp[bx], mp[by]};
    }
    L = mp[L];
    U = mp[U];
    R = mp[R];
    D = mp[D];
    // cerr << "L: " << L << ", U: " << U << ", R: " << R << ", D: " << D << '\n';
    sort(Nodes.begin(), Nodes.end(), [](const Line& a, const Line& b) {
        if(a.ay!=b.ay) return a.ay < b.ay;
        if(a.ax!=b.ax) return a.ax < b.ax;
        if(a.ay==D) {
            if(a.bx!=b.bx) return a.bx < b.bx;
            if(a.bx==L) {
                return a.by < b.by;
            } else return a.by > b.by;
        } else {
            if(a.bx!=b.bx) return a.bx < b.bx;
            return a.by < b.by;
        }
        
    });

    BIT ceil(1e6), right(1e6), left(1e6);
    auto update_node = [&](int x, int y) {
        if(x==L) {
            left.update(y);
        } else if(x==R) {
            right.update(y);
        } else if(y==U) {
            ceil.update(x);
        }
    };
    uint64_t ans(0);
    int tx = -1, ty = -1;
    queue<pair<int, int> > q; 
    for(auto node: Nodes) {
        if(tx!=node.ax or ty!=node.ay) {
            while(not q.empty()) {
                update_node(q.front().first, q.front().second); q.pop();
            }
            tx = node.ax;
            ty = node.ay;
        }
        int tmp = ans;
        if(node.ay==D) {
            if(node.bx==R) {
                ans += right.query(node.by-1);
            } else if(node.by==U) {
                ans += ceil.query(1e6) - ceil.query(node.bx);
                ans += right.query(1e6);
            } else if(node.bx==L) {
                ans += left.query(1e6) - left.query(node.by);
                ans += ceil.query(1e6);
                ans += right.query(1e6);
            }
        } else {
            if(node.ax > node.bx) {
                swap(node.ax, node.bx);
                swap(node.ay, node.by);
            }
            ans += ceil.query(node.bx-1) - ceil.query(node.ax);
            ans += left.query(1e6) - left.query(node.ay);
            ans += right.query(1e6) - right.query(node.by);
        }
        // cerr << "Processing node: (" << node.ax << ", " << node.ay << ") to (" << node.bx << ", " << node.by << ")-> " << ans-tmp << '\n';

        // update_node(node.ax, node.ay);
        q.push({node.bx, node.by});
        // cerr << '\n';
    }
    cout << ans;
    return 0;
}