#include <iostream>
using namespace std;
 
 
const int MOD = 1e9 + 7;
int N;
int FIB[(int)1e5+1] = {1, 1, 1};
int main(){
    cin >> N;
    for(int i=3;i<=N;++i)
        FIB[i] = (FIB[i-1] + FIB[i-2]) % MOD;
    cout << FIB[N] << '\n';
    return 0;
}