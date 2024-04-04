#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> Nums(N);
    for(int &i: Nums) {
        cin >> i;
    }
    sort(Nums.begin(), Nums.end());
    int P = Nums[N/2];
    uint64_t ans = 0;
    for(int i=0;i<N;++i) {
        ans += abs(1LL*Nums[i]-P);
    }
    cout << ans << '\n';
    return 0;
}