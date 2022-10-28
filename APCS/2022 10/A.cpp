#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<pair<int, int> > Nums(N);
    for(pair<int, int> &i: Nums) cin >> i.first >> i.second;
    vector<int> dis(N-1);
    for(int i=1;i<N;++i) {
        dis[i-1] = abs(Nums[i].first - Nums[i-1].first) + abs(Nums[i].second - Nums[i-1].second);
    }
    sort(dis.begin(), dis.end());
    cout << dis[N-2] << ' ' << dis[0] << '\n'; 
    return 0;
}