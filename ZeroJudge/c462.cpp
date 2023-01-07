#include <iostream>
#include <vector>
#include <cctype>
using namespace std;


int main() {
    int K;
    string S;
    vector<int> cnt;
    cin >> K >> S;
    int l=0;
    while(l<S.size()) {
        int r=l;
        while(r < S.size() and isupper(S[l]) == isupper(S[r])) {
            r++;
        }
        cnt.push_back(r-l);
        l = r;
    }
    vector<pair<int, int> > all_k;
    l=0;
    while(l<cnt.size()) {
        while(l < cnt.size() and cnt[l] != K) ++l;
        if(l==cnt.size()) break;

        int r=l;
        while(r < cnt.size() and cnt[r] == K) {
            r++;
        }
        all_k.push_back(make_pair(l, r));
        l = r;
    }
    int ans = 0;
    for(auto i: all_k) {
        
        int len = i.second - i.first;
        if(i.first != 0 and cnt[i.first-1] > K)
            ++len;
        if(i.second != cnt.size() and cnt[i.second] > K)
            ++len;
        ans = max(ans, K*len);
    }
    for(int i=1;i<cnt.size();++i) {
        if(cnt[i-1]>=K and cnt[i]>=K)
            ans = max(ans, K*2);
    }
    for(int i=0;i<cnt.size();++i) {
        if(cnt[i] >= K)
            ans = max(ans, K);
    }
    cout << ans << '\n';
    return 0;
}
