#include <iostream>
using namespace std;

const int MAX_N = 2e5;
int N, M;
int mx[MAX_N<<2];
int nums[MAX_N];
void update(int x, int u, int l, int r) {
    if(l==r) {
        mx[u] = nums[l];
        return;
    }
    int mid=l+(r-l)/2;
    if(x<=mid) update(x, u<<1, l, mid);
    else update(x, u<<1|1, mid+1, r);
    mx[u] = max(mx[u<<1], mx[u<<1|1]);
}
int query(int minValue, int u, int l, int r) {
    if(l==r) return l;
    int mid=l+(r-l)/2;
    if(minValue<=mx[u<<1]) return query(minValue, u<<1, l, mid);
    else return query(minValue, u<<1|1, mid+1, r);
}
int main() {
    cin >> N >> M;
    fill(nums, nums+MAX_N, 0);
    for(int i=1;i<=N;++i) {
        cin >> nums[i];
        update(i, 1, 1, N);
    }
    for(int i=0;i<M;++i) {
        int x;
        cin >> x;
        if(x<=mx[1]) { 
            int result = query(x, 1, 1, N);
            nums[result] -= x;
            update(result, 1, 1, N);
            cout << result << ' ';
        } else {
            cout << "0 ";
        }
    }
    cout << '\n';
    return 0;
}