#include <iostream>
#include <map>
#include <set>
using namespace std;
#define lowbit(x) (x&-x)

const int MAX_N = 2e5 + 5;
int BIT[MAX_N];
int Nums[MAX_N];
void update(int x, int v) {
    x++;
    for(;x<=MAX_N;x+=lowbit(x)) {
        BIT[x] += v;
    }
}
int query(int x) {
    x++;
    int ans=0;
    for(;x>0;x-=lowbit(x)) {
        ans += BIT[x];
    }
    return ans;
}
int main() {
    int N;
    cin >> N;
    for(int i=0;i<N;++i) {
        cin >> Nums[i];
    }
    for(int i=0;i<N;++i) {
        update(i, 1);
    }
    for(int kase=0;kase<N;++kase) {
        int x;
        cin >> x;
        int l=-1, r=MAX_N;
        while(r-l>1) {
            int mid = (r+l)/2;
            if(x<=query(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << Nums[r] << ' ';
        update(r, -1);
    }
    cout << '\n';
    return 0;
}