#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    uint64_t N;
    cin >> T;
    while(T--){
        cin >> N;
        if(N == 1){
            cout << 1 << '\n';
            continue;
        }
        int factor[10] = {0};
        for(int i=9;i>=2;--i){
            while(N%i == 0){
                ++factor[i];
                N /= i;
            }
            // cout << i << ' ' << factor[i] << '\n';
        }
        if(N != 1)
            cout << -1 << '\n';
        else{
            for(int i=2;i<=9;++i){
                for(int j=0;j<factor[i];++j)
                    cout << i;
            }
            cout << '\n';
        }
    }
    return 0;
}
