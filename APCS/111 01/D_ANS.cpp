#include <bits/stdc++.h>
using namespace std;
 
int n, k, h[200005], w[50005];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int l = 1, r = 0;
    for (int i = 1; i <= n; i++){
        cin >> h[i];
        r = max(r, h[i]);
    }
    r++;
    for (int i = 1; i <= k; i++){
        cin >> w[i];
    }
    while (r-l > 1){
        int mid = (l+r)/2;
        int cnt = 0, now = 1;
        bool flag = false;
        for (int i = 1; i <= n; i++){
            if (h[i] >= mid){
                cnt++;
                if (cnt >= w[now]){
                    cnt -= w[now];
                    if (now == k){
                        flag = true;
                        break;
                    }
                    now++;
                }
            }
            else cnt = 0;
        }
        if (flag) l = mid;
        else r = mid;
    }
    cout << l << "\n";
}