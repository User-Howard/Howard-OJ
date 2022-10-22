#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> ColorMap;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int M, N;
    cin >> M >> N;
    vector<string> colors(N);
    for(string &i: colors) cin >> i;
    int ans = 0;
    int cnt = 0;
    for(int i=0;i<N;++i) {
        if (i >= M and (--ColorMap[colors[i - M]])==0)
            --cnt;
        if((ColorMap[colors[i]]++) == 0)
            ++cnt;
        if(cnt == M)
            ++ans;
    }
    cout << ans << '\n';
    return 0;
}
// 我已經用unordered_map 來處理計數上的問題（原本是用set，我有點本末倒置了）。