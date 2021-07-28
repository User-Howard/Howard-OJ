#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct Edge{
    int lb, rb, mid;
    int val;
};
int N, M;
vector<int> nums;
vector<Edge> MAX;
void init(int u, int l, int r){
    while(u >= MAX.size())
        MAX.push_back(Edge());
    MAX[u].lb = l, MAX[u].rb = r, MAX[u].mid = (l + r) / 2;
    if(l < r){
        int m = (l + r) / 2;
        init(2*u, l, m);
        init(2*u+1, m+1, r);
    }
}
void add(int u, int i, int x){
    MAX[u].val = max(x, MAX[u].val);
    if(MAX[u].lb != MAX[u].rb){
        int m = MAX[u].mid;
        if(i <= m)
            add(2*u, i, x);
        else
            add(2*u+1, i, x);
    }
}
int get_max(int u, int a, int b){
    if(a <= MAX[u].lb and MAX[u].rb <= b)
        return MAX[u].val;
    int max_item = 0;
    int m = MAX[u].mid;
    if(a <= m) max_item = max(max_item, get_max(u*2, a, b));
    if(m < b) max_item = max(max_item, get_max(u*2+1, a, b));
    return max_item;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    nums.resize(N);
    for(int i=0;i < N;++i)
        cin >> nums[i];
    init(1, 0, N-1);
    for(int i = 0;i < N;++i)
        add(1, i, nums[i]);
    cin >> M;
    while(M--){
        int a, b;
        cin >> a >> b;
        if(b < a)
            swap(a, b);
        cout << get_max(1, a-1, b-1) << '\n';
    }
    return 0;
}