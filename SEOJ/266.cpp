#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct HASH{
    const int K = 100;
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
            h[i] = (h[i-1] * K + s[i-1]) % MOD;
    }
    uint64_t query(const int l, const int r){
        return (h[r] - h[l-1] * k_pow[r - l] + MOD) % MOD;
    }
};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int N, M;
    HASH H;
    unordered_map<int, int> mp;
    cin >> N >> M;
    for(int i=0;i<N;++i){
        string s;
        cin >> s;
        H.build(s);
        mp[H.query(1, s.size())] += 1;
    }
    for(int i=0;i<M;++i){
        string s;
        cin >> s;
        H.build(s);
        cout << mp[H.query(1, s.size())] << '\n';
    }
    return 0;
}