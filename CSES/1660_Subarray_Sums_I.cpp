#include <iostream>
#include <algorithm>
using namespace std;


const int MAX_N = 2e5 + 5;
int main() {
    int N, M;
    int Nums[MAX_N];
    cin >> N >> M;
    for(int i=0;i<N;++i)
        cin >> Nums[i];
    int pointer = 0, answer = 0;
    uint64_t count = 0;
    for(int i=0;i<N;++i) {
        count += Nums[i];
        while(count > M) count -= Nums[pointer++];
        if(count == M) ++answer;
    }
    cout << answer << '\n';
    return 0;
}
