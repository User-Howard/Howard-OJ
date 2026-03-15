#include <iostream>
using namespace std;


void solve(int n, int a, int b) {
    int r = n-a-b;
    if(r<0) {
        cout << "NO\n";
        return;
    }

    if((a==0 or b==0) and (a+b>0)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    for(int i=1;i<=a;++i) cout << b+i << ' ';
    for(int i=1;i<=b;++i) cout << i << ' ';
    for(int i=1;i<=r;++i) cout << a+b+i << ' ';
    cout << '\n';

    for(int i=1;i<=a;++i) cout << i << ' ';
    for(int i=1;i<=b;++i) cout << a+i << ' ';
    for(int i=1;i<=r;++i) cout << a+b+i << ' ';
    cout << '\n';
}
int main() {
    int N;
    cin >> N;
    while(N--) {
        int n, a, b;
        cin >> n >> a >> b;
        solve(n, a, b);
    }

    return 0;
}
