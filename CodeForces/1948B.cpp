#include <iostream>
#include <vector>
using namespace std;

bool solve() {
    int N;
    cin >> N;
    vector<int> Nums(N);
    for(int &i: Nums) cin >> i;
    int tmp = Nums[N-1];
    for(int i=N-2;i>=0;--i) {
        if(Nums[i] > tmp) {
            int A = Nums[i] / 10;
            int B = Nums[i] % 10;
            if(B <= tmp and A<=B) {
                tmp = A;
            } else {
                return false;
            }
        }
        else {
            tmp = Nums[i];
        }
    }
    return true;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}