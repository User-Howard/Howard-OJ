#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector<int> Nums(N);
        for(int &i: Nums) cin >> i;
        sort(Nums.begin(), Nums.end());
        int mid = Nums[N/2], ans = 0;
        for(int i: Nums) {
            ans += abs(i - mid);
        }
        cout << ans << '\n';
    }
    return 0;
}
