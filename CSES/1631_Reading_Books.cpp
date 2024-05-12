#include <functional>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> Nums(N);
    for(int i=0;i<N;++i) {
        cin >> Nums[i];
    }
    sort(Nums.begin(), Nums.end());
    int64_t sum = accumulate(Nums.begin(), Nums.end(), 0LL);
    if(sum-Nums.back() > Nums.back()) {
        cout << sum << '\n';
    }
    else {
        cout << 2*Nums.back() << '\n';
    }

    return 0;
}
