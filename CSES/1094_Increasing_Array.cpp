#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N;
    cin>>N;
    vector<int>Nums(N);
    for(int &i:Nums) cin>>i;
    uint64_t ans = 0;
    int t = Nums[0];
    for(int i : Nums) {
        ans += max(0, t-i);
        t = max(t, i);
    }
    cout<<ans<<'\n';
    return 0;
}