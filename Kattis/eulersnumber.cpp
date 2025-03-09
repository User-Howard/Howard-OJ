#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;


int main(){
    int N;
    cin >> N;
    double T=1;
    vector<uint64_t> dp(100000);
    dp[0] = 1;
    for(int i=1;i<=N;++i) {
        dp[i] = dp[i-1] * i;
        if(dp[i]>10000000000000) break;
        T += 1.0/dp[i];
    }
    cout << fixed << setprecision(15) << T << endl;
    return 0;
}