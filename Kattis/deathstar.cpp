#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;++i) {
        int t = 0;
        for(int j=0;j<N;++j) {
            int x;
            cin >> x;
            t |= x;
        }
        cout << t << ' ';
    }
    cout << '\n';
    return 0;
}