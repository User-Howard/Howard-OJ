#include <cstdio>
#include <iomanip>
#include <iostream>
#include <iterator>
using namespace std;


int tenPow(int x) {
    if(x==0) return 1;
    if(x==1) return 10;
    if(x==2) return 100;
    if(x==3) return 1000;
    if(x==4) return 10000;
    if(x==5) return 100000;
}
int N;
void solve() {
    for(int i=0;i<tenPow(N/2);++i) {
        for(int j=0;j<tenPow(N/2);++j) {
            int num = i * tenPow(N/2) + j;
            if((i+j)*(i+j) == num) {
                cout << setfill('0') << setw(N) << num << '\n';
            }
        }
    }
}
int main() {
    while(cin >> N) {
        solve();
    }
}
