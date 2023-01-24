#include <iostream>
#include <vector>
using namespace std;


const int MAX_N = 1e4+2;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> primeNumber;
    vector<bool> isPrimeNumber(MAX_N, true);
    for(int i=2;i<MAX_N;++i) {
        if(isPrimeNumber[i]) {
            primeNumber.push_back(i);
            for(int j=2;i*j<MAX_N;++j) {
                isPrimeNumber[i*j] = false;
            }
        }
    }
    int N;
    while(cin >> N and N) {
        int ans = 0;
        for(int i=0;i<primeNumber.size();++i) {
            if(N < primeNumber[i])
                break;
            int t = 0;
            for(int j=i;j<primeNumber.size();++j) {
                t += primeNumber[j];
                if(t==N) {
                    cout << i << ' ' << j << '\n';
                    ++ans;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
// 228K	63MS