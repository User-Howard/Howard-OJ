// https://zerojudge.tw/ShowProblem?problemid=h090
#include <iostream>
using namespace std;


const int MAX_N = 2e5 + 4;
const int MOD = 998244353;
string S;
uint64_t pre[MAX_N] = {0};
uint64_t pow10[MAX_N] = {1}; // 1, 10, 100
uint64_t pow2[MAX_N] = {1};  // 1, 2, 4
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> S;
    for(int i=0;i<S.size();++i)
        pre[i+1] = pre[i] + S[i] - '0';
    for(int i=1;i<S.size();++i){
        pow10[i] = 10 * pow10[i-1] % MOD;
        pow2[i] = (pow2[i-1] << 1 ) % MOD;
    }
    uint64_t ans = 0;
    for(int i=2;i<=S.size();++i){
        ans += (pre[i] * pow10[S.size() - i] % MOD) * pow2[i-2] % MOD;
        ans %= MOD;
        ans += ((pre[i] - pre[i-1]) * pow10[S.size() - i] % MOD) * pow2[i-2] % MOD;
        ans %= MOD;
    }
    ans += (pre[1]) * pow10[S.size() - 1] % MOD;
    ans %= MOD;
    cout << ans << '\n';
    return 0;
}
/*
1*1*4 V 
2*1*4 V 
3*1*4  V 
4*1*8 V 
40 + 16

1*10*2 V 
2*10*2 V 
3*10*4 V 
120 + 60

1*100*1 V 
2*100*2 V 
300 + 200

1*1000*1 V 
0 + 1000
*/