#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
inline int arithmetic(int x){
    return x*(x-1)/2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b, S;
    cin >> a >> b;
    reverse(a.begin(),a.end());
    S = a + b;
    int cnt_w, cnt_y, sum_w, sum_y;
    cnt_w = cnt_y = sum_w = sum_y = 0;
    for(int i=0;i<S.size();i++){
        if(S[i]=='W'){
            sum_w += i;
            ++cnt_w;
        }
    }
    cnt_y = S.size() - cnt_w;
    sum_y = arithmetic(S.size()) - sum_w;
    int ans = min(sum_w - arithmetic(cnt_w), sum_y - arithmetic(cnt_y));
    cout << ans << " \n";
    return 0;
}
