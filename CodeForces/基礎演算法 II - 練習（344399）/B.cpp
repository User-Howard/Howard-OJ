#include <iostream>
using namespace std;


int N, ans;
int d[18]={0}, used[17]={0};
bool is_prime[32] = {0, 0};
void make_is_prime(){
    fill(is_prime+2, is_prime+32, true);
    for(int i=2;i<32;++i)
        if(is_prime[i])
            for(int j=i*2;j<32;j+=i)
                is_prime[j] = false;
}
void solve(int pos=1){
    if(pos>N){
        if(is_prime[d[N-1]])
            ++ans;
        return;
    }
    for(int i=1;i<=N;++i){
        if(pos != 1 and (used[i] or !is_prime[d[pos - 2] + i]))
            continue;
        used[i] = true;
        d[pos] = i;
        solve(pos+1);
        used[i] = false;
    }
}
int main(){
    cin >> N;
    make_is_prime();
    solve();
    cout << ans << '\n';
    return 0;
}