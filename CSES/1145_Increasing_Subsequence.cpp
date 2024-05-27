#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> Nums(N);
    for(int &i: Nums)
        cin >> i;
    vector<int> LIS;
    for(int i: Nums) {
        if(LIS.empty() or LIS.back() < i) {
            LIS.push_back(i);
        } else {
            LIS[distance(LIS.begin(), lower_bound(LIS.begin(), LIS.end(), i))] = i;
        }
    }
    cout << LIS.size() << '\n';
    return 0;
}
