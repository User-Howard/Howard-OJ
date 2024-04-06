#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define all(x) x.begin(),x.end()
 
int main() {
    int N;
    cin >> N;
    vector<int> Nums(N);
    for(int &i: Nums) cin >> i;
    int answer = 0;
    vector<int> dp;
    for(int i: Nums) {
        int result = distance(dp.begin(), upper_bound(all(dp), i));
        // cout << result << '\n';
        if(result==dp.size()) {
            dp.push_back(i);
            answer++;
        } else {
            dp[result] = i;
        }
    }
    cout << answer << '\n';
    return 0;
}