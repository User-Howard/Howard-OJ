#include <iostream>
#include <bitset>
#include <vector>


const int maxn = 1e9+1;
std::bitset<maxn> exists;
int main() {
    int N;
    std::cin >> N;
    std::vector<int> Nums(N);
    for(int &i: Nums) std::cin >> i;
    int ptr = 0;
    uint64_t ans = 0;
    for(int i=0;i<N;++i) {
        if(i) exists[Nums[i-1]] = false;
        while(ptr<N and not exists[Nums[ptr]]) exists[Nums[ptr++]] = true;
        ans += ptr-i;
    }
    std::cout << ans << '\n';
    return 0;
}
