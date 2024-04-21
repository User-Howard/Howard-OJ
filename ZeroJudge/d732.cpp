#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int N, K;
    cin >> N >> K;
    map<int, int> Nums;
    for(int i=0;i<N;++i) {
        int x;
        cin >> x;
        Nums[x] = i+1;
    }
    for(int i=0;i<K;++i) {
        int x;
        cin >> x;
        auto result = Nums.find(x);
        if(result != Nums.end())
            cout << (result->second) << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}