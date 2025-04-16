#pragma GCC optimize("Ofast,no-stack-protector")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#define int long long
#define quick ios::sync_with_stdio(0);cin.tie(0);
#define rep(x,a,b) for(int x=a;x<=b;x++)
#define repd(x,a,b) for(int x=a;x>=b;x--)
#define lowbit(x) (x&-x)
#define sz(x) (int)(x.size())
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define eb emplace_back
using namespace std;
typedef pair<int,int> pii;
void debug(){
    cout<<"\n";
}
template <class T,class ... U >
void debug(T a, U ... b){
    cout<<a<<" ",debug(b...);
}
const int INF=1e18;

vector<int> blank;
vector<char> vowels = {'A', 'E', 'I', 'O', 'U'};
int ans = 0;
bool isVowel(char c) {
    return c=='A' or c=='E' or c=='I' or c=='O' or c=='U';
}
void solve(string s, int x) {
    if(x==blank.size()) {
        bool flag = false;
        for(char c: s) {
            if(c=='L') {
                flag = true;
                break;
            }
        }
        if(not flag) return;
        int n=1;
        for(int i: blank) {
            if(s[i]=='A') n *= 5;
            if(s[i]=='B') n *= 20;
        }
        ans += n;
        return;
    }
    for(char c: string("ABL")) {
        s[blank[x]] = c;
        bool good_str = true;
        for (int i = 0; i < 3; ++i) {
            int v = blank[x]+i;
            if(v>=s.size()) break;
            if(s[v]=='_') break;
            if (v >= 2) {
                if (isVowel(s[v]) and isVowel(s[v-1]) and isVowel(s[v-2])) {
                    good_str = false;
                    break;
                }
                if (not isVowel(s[v]) and not isVowel(s[v-1]) and not isVowel(s[v-2])) {
                    good_str = false;
                    break;
                }
            }
        }
        if(good_str) {
            solve(s, x+1);
        }
    }
}
signed main(){
    quick
    string s;
    cin >> s;
    for(int i=0;i<s.size();++i) {
        if(s[i]=='_') blank.push_back(i);
    }
    solve(s, 0);
    cout << ans << '\n';
    return 0;
}