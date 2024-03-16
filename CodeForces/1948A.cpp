#include <iostream>
using namespace std;


int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        if(N%2) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            int j=0;
            for(int i=0;i<N/2;++i) {
                cout << char('A'+j) << char('A'+j);
                j = 1-j;
            }
            cout << '\n';
        }
    }
    return 0;
}