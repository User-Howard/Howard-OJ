#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int N, Q;
vector<int> Nums;
bool solve(int x) {
    int lp = 0;
    int rp = 0;
    for(;lp<Nums.size();++lp) {
        while(rp<Nums.size() and Nums[rp]-Nums[lp]<x) rp++;
        if(rp==Nums.size()) break;
        if(Nums[rp]-Nums[lp]==x) return true;
    }
    return false;
}
int main() {
    cin >> N >> Q;
    Nums.resize(N);
    for(auto &i: Nums) cin >> i;
    sort(Nums.begin(), Nums.end());

    while(Q--) {
        int x;
        cin >> x;
        if(solve(x)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
