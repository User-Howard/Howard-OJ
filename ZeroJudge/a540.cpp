#include<iostream>
#include<algorithm>
using namespace std;

void solve(int N){
    int ans=0;
    int pre=0;
    for(int i=0, m;i<N;i++){
        cin >> m;
        pre += m;
        if(pre<0)
            pre = 0;
        else
            ans = max(pre, ans);
    }
    if(ans)
        cout << "The maximum winning streak is " << ans << ".\n";
    else
        cout << "Losing streak.\n";
}
int main(){
    int N;
    while(cin >> N && N)
        solve(N);
    return 0;
}