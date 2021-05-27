#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;


int N;
int bit[(int)(1e5 + 2)] = { 0 };
uint64_t nums[(int)(1e5+2)];
uint64_t record[(int)(1e5+2)];
void update(int i, int x) {
    while (i <= N) {
        bit[i] += x;
        i += i & -i;
    }
    return;
}
int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> N) {
        memset(bit, 0, sizeof(bit));
        for(int i=0;i<N;i++)
            cin>>nums[i];
        copy(nums, nums+N, record);
        sort(nums, nums+N);
        for(int i=1;i<=N;i++){
            int t = lower_bound(nums, nums + N, record[i - 1]) - nums + 1;
            update(t, 1);
            cout<<i - sum(t) + 1<<'\n';
        }
    }

    return 0;
}