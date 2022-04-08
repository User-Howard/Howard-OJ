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
        int factor[10];
        for(int i=9;i>0;--i){
            while(N%i == 0){
                ++factor[i];
                N /= i;
            }
        }
        if(N != 1)
            cout << -1 << '\n';
        else{
            for(int i=1;i<=9;++i){
                for(int j=0;j<factor[i];++j)
                    cout << i;
            }
            cout << '\n';
        }
    }
    return 0;
}
