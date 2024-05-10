#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N =2e5 + 5;
int N;
int block[MAX_N] = {1};
int64_t Nums[MAX_N];
int64_t prefix[MAX_N];
int main() {
    cin >> N;
    for(int i=0;i<N;++i)
        cin >> Nums[i];
    for(int i=0;i<N;++i) {
        prefix[i] = Nums[i];
        if(i != 0) prefix[i] += prefix[i-1];
    }
    uint64_t answer = 0;
    for(int i=0;i<N;++i) {
        int lost = (prefix[i] % N + N) % N;
        answer += block[lost];
        ++block[lost];
    }
    cout << answer << '\n';
    return 0;
}
