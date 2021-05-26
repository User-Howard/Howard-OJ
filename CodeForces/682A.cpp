#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll;


int An[5], Am[5];
int main(){
    int N, M;
    cin>>N>>M;
    fill(begin(An), end(An), N/5);
    fill(An+1, next(An+N-(N/5)*5), N/5+1);
    fill(begin(Am), end(Am), M/5);
    fill(Am+1, next(Am+M-(M/5)*5), M/5+1);
    uint64_t ans = (ll)An[0]*(ll)Am[0];
    for(int i=1;i<5;i++)
        ans += (ll)An[i]*(ll)Am[5-i];
    cout<<ans<<'\n';
    return 0;
}