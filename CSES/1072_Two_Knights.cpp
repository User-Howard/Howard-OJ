#include <iostream>
using namespace std;


int main() {
    int N;
    cin>>N;
    for(int i = 1;i<=N;++i) {
        uint64_t ans = (1LL*i*i*i*i-1LL*i*i)/2;
        if(i>=3) {
            ans -= 4*(i-2)*(i-1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}