#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> Nums(N);
    for(int &i: Nums) cin >> i;
    sort(Nums.begin(), Nums.end());
    uint64_t s = 0;
    for(int i: Nums) {
        if(s+1<i) {
            cout << s+1 << '\n';
            return 0;
        }
        s += i;
    }
    cout << s+1 << '\n';
    return 0;
}