#include <iostream>
#include <vector>
using namespace std;

const int K = 128;
const uint64_t MOD = 1e9+7;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string S, T;
    cin >> S >> T;
    const int S_size = S.size(), T_size = T.size();
    uint64_t hs=0, ht=0, k_pow = 1;
    for(int i=0;i<S_size;++i)
        hs = (hs*K + S[i]) % MOD;
    for(int i=0;i<S_size;++i)
        ht = (ht*K + T[i]) % MOD;
    for(int i=1;i<S_size;++i)
        k_pow = (k_pow*K) % MOD;
    // cout << hs << "\n\n";
    bool fp = true;
    for(int i=0;i+S_size<=T_size;++i){
        if(i != 0){
            ht = (ht - (T[i-1])*k_pow + MOD*MOD) % MOD;
            ht = (ht*K + T[i+S_size-1]) % MOD;
        }
        if(hs==ht){
            if(!fp) cout << ' ';
            cout << i;
            fp = false;
            // cout << '\n';
        }
        // cout << ht << '\n';
    }
    cout << '\n';
    return 0;
}