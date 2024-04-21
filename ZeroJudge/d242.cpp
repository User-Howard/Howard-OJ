#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int x;
    vector<int> Nums;
    while (cin >> x) {
        Nums.push_back(x);
    }
    const int N = Nums.size();
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
    vector<int> answer;
    int r = dp.size()-1;
    for(int i=N-1;i>=0;--i) {
        if(rec[i] == r) {
            answer.push_back(Nums[i]);
            r--;
        }
    }
    cout << answer.size() << "\n-\n";
    reverse(answer.begin(), answer.end());
    for(int i:answer) 
        cout << i << '\n';
    
    return 0;
}