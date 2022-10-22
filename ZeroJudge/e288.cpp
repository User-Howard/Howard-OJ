#include <iostream>
#include <unordered_map>
using namespace std;


int charToDigit(char c) {
    if('A' <= c and c <= 'Z')
        return c - 'A';
    else
        return c - 'a' + 26;
}
unordered_map<int64_t, int> MP;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int M, N;
    cin >> M >> N;
    uint64_t mask = ((uint64_t)1 << M) - 1;
    int ans = 0;
    for(int i=0;i<N;++i) {
        string S;
        uint64_t tmp = 0;
        cin >> S;
        for(char c: S) {
            tmp |= (uint64_t)1<<charToDigit(c);
        }
        if(MP.find(tmp^mask) != MP.end())
            ans += MP[tmp^mask];
        MP[tmp] ++;
    }
    cout << ans << '\n';
    return 0;
}