#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int64_t> Nums(N);
    for(int64_t &i: Nums) cin >> i;
    if(*max_element(Nums.begin(), Nums.end()) < 0) {
        cout << *max_element(Nums.begin(), Nums.end()) << '\n';
        return 0;
    }
    int64_t t=0, answer = -1;
    for(int i: Nums) {
        t = max(t+i, (int64_t)0);
        answer = max(answer, t);
    }
    cout << answer << '\n';

    return 0;
}
