#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


typedef pair<int, int> pii;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T, N;
    vector<pii> D;
    cin >> T;
    while(T--){
        cin >> N;
        D.resize(N);
        for(pii &i:D)
            cin >> i.second >> i.first;
        sort(D.begin(), D.end(), greater<pii>());
        int ans = 0, prev_time = 0;
        for(pii i:D){
            prev_time += i.second;
            ans = max(ans, prev_time + i.first);
        }
        cout << ans << '\n';
    }
    return 0;
}
