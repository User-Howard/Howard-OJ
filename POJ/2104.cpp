#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define all(x) x.begin(),x.end()


const int MAX_N = 1e5+5;
int N, Q;
struct Node {
    vector<int> vc;
    int l, r;
    Node() {}
    Node(int l, int r): l(l), r(r) {}
} Tree[MAX_N<<2];

void build(int u,int ul, int ur) {
    Tree[u] = Node(ul, ur);
    if(ur-ul>1) {
        int mid = ul+(ur-ul)/2;
        build(u<<1, ul, mid);
        build(u<<1|1, mid, ur);
        Tree[u].vc.resize(ur-ul);
        merge(all(Tree[u<<1].vc), all(Tree[u<<1|1].vc), Tree[u].vc.begin());
    } else {
        Tree[u].vc.resize(1);
        cin >> Tree[u].vc[0];
    }
}

int query(int u, int l, int r, int x, int tb=0) {
    Node &t = Tree[u];
    // for(int i=0;i<tb;++i) cerr << "\t";
    // cerr << "query(" << u << ", " << l << ", " << r << ") at range(" << t.l << ", " << t.r << ")\n";
    int mid = t.l + (t.r-t.l)/2;
    if(r<=t.l or t.r<=l) return 0;
    if(l<=t.l and t.r<=r)
        return distance(t.vc.begin(), upper_bound(all(t.vc), x));
    

    int q(0);
    if(l<mid) {
        q += query(u<<1, l, r, x, tb+1);
    }
    if(mid<=r) {
        q += query(u<<1|1, l, r, x, tb+1);
    }
    return q;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> N >> Q;
    build(1, 0, N);
    while(Q--) {
        int x, y, k;
        cin >> x >> y >> k;
        int l(-1e9), r(1e9+1); // (] 
        while(r-l>1) {
            int mid = l+(r-l)/2;
            // cout << "try " << mid << " when " << l << ' ' << r << '\n';
            if(query(1, x-1, y, mid)<k) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << r << '\n';
    }
    
    return 0;
}