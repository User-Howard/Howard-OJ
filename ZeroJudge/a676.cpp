#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> G(N), Nums(N);
    for(int i=0;i<N;++i) {
        cin >> G[i];
    }
    while(cin >> Nums[G[0]-1]) {
        for(int i=1;i<N;++i) {
            cin >> Nums[G[i]-1];
        }
        vector<int> dp, rec;

        for (int num: Nums) {
            auto result = lower_bound(dp.begin(), dp.end(), num);
            rec.push_back(distance(dp.begin(), result));
            if (result == dp.end()) {
                dp.push_back(num);
            }
            else {
                dp[distance(dp.begin(), result)] = num;
            }
        }
        cout << dp.size() << '\n';
    }
    return 0;
}