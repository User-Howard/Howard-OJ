#include <iostream>
#include <vector>
using namespace std;

struct HASH{
    const int K = 26;
    const int MOD = 1e9+7;
    vector<uint64_t> h;
    vector<uint64_t> k_pow;
    void build(string &s){
        k_pow.resize(s.size());
        h.resize(s.size()+1);
        k_pow[0] = 1;
        for(int i=1;i<s.size();++i)
            k_pow[i] = k_pow[i-1] * K % MOD;
        h[0] = 0;
        for(int i=1;i<=s.size();++i)
            h[i] = (h[i-1] * K + s[i-1] - 96) % MOD;
    }
    uint64_t query(const int l, const int r){
        return (h[r] - h[l-1] * k_pow[r - l + 1] + MOD) % MOD;
    }
}hs, ht;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string S, T;
    int k;
    cin >> S >> k;
    hs.build(S);
    while(k--){
        cin >> T;
        if(T.size() > S.size()){
            cout << "NO\n";
            continue;
        }
        ht.build(T);
        int t_val = ht.query(1, T.size());
        bool f = false;
        for(int i=0;i<=S.size()-T.size();++i){
            if(hs.query(i+1, i+T.size()) == t_val){
                f = true;
                break;
            }
        }
        if(f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}