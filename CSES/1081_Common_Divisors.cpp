#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int T;
    cin >> T;
    vector<int> check(1e6+5);
    for(int i=0;i<T;++i) {
        static int x;
        cin >> x;
        check[x]++;
    }
    for(int i=1e6;i>=1;--i) {
        int cnt = 0;
        for(int j=i;j<=1e6;j+=i) {
            cnt += check[j];
        }
        if(cnt>=2) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
