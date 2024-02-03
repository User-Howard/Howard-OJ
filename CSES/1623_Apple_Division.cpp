#include <iostream>
#include <numeric>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N;
long long sum_of_Nums;
vector<int> Nums(20, 0);
const long long INF = 2e10;
long long solve(int x=0, long long s=0) {
    if(s > sum_of_Nums/2) return -INF;
    if(x==N) return s;
    return max(solve(x+1, s), solve(x+1, s+Nums[x]));
}
int main() {
    cin >> N;
    for(int i=0;i<N;++i)
        cin >> Nums[i];
    sum_of_Nums = accumulate(Nums.begin(), Nums.begin()+N, 0LL);
    cout << sum_of_Nums - 2*solve() << '\n';

    return 0;
}