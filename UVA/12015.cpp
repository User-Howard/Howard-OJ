#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int T;
    cin >> T;
    for(int kase=1;kase<=T;++kase) {
        cout << "Case #" << kase << ":\n";
        vector<string> S(10);
        vector<int> Rate(10);
        for(int i=0;i<10;++i) {
            cin >> S[i] >> Rate[i];
        }
        int maxRate = *max_element(Rate.begin(), Rate.end());
        for(int i=0;i<10;++i) {
            if(Rate[i] == maxRate) {
                cout << S[i] << '\n';
            }
        }
    }
    return 0;
}
