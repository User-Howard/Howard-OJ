#include <iostream>
#include <set>
#include <vector>
using namespace std;


const int INF = 1e9;
const int MAX_N = 1e6 + 5;
vector<int> dp(MAX_N, -1);
int find_distance(int x) {
    if(dp[x]!=-1)
        return dp[x];


    set<int> allDigits;
    for(int i=x;i!=0;i/=10) {
        allDigits.insert(i%10);
    }
    allDigits.erase(0);
    int ans = INF;
    for(int digit: allDigits) {
        ans = min(ans, 1 + find_distance(x - digit));
    }
    return dp[x] = ans;
}
int main() {
    int N;
    cin >> N;
    dp[0] = 0;
    cout << find_distance(N) << '\n';
    return 0;
}
