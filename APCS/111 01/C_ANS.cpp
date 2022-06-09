#include <bits/stdc++.h>
using namespace std;
 
int m, ans;
string s[50005];
set <string> st;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> s[i];
        st.insert(s[i]);
    }
    for (int i = 0; i < m; i++){
        int l = s[i].length();
        if (l < 3) continue;
        for (int j = 1; j <= l/2; j++){
            if (s[i].substr(0, j) == s[i].substr(l-j, j)){
                if (st.count(s[i].substr(j, l-j-j))) ans++;
            }
        }
    }
    cout << ans << "\n";
}
