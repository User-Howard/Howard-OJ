#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;


int main() {
    int N, X;
    cin >> N >> X;
    vector<int> Nums(N);
    map<int, priority_queue<int> > rec;
    for(int &i: Nums) cin >> i;
    for(int i=0;i<N;++i) {
        rec[Nums[i]].push(i);
    }
    for(int i=0;i<N;++i) {
        for(int j=i+1;j<N;++j) {
            const int rest = X-Nums[i]-Nums[j];
            if(rec.find(rest)==rec.end()) continue;
            if(rec[rest].top() > j) {
                cout << i+1 << ' ' << j+1 << ' ' << rec[rest].top()+1 << '\n';
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
