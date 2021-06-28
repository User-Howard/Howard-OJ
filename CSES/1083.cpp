#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int64_t n, s=0;
    cin >> n;
    for(int i=1;i<n;++i){
        int num;
        cin >> num;
        s += num;
    }
    cout << (n+1)*n/2-s << '\n';
    return 0;
}
