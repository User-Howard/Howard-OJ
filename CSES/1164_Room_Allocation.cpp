#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
typedef pair<int, int> pii;

int main() {
    vector<tuple<int, int, int > > Nums;

    int N;
    cin >> N;
    for(int i=0;i<N;++i) {
        int f, e;
        cin >> f >> e;
        Nums.push_back(make_tuple(f, e, i));
    }
    sort(Nums.begin(), Nums.end());
    priority_queue<pii, vector<pii>, greater<pii> > q;
    vector<int> rec(N);
    for(int i=0;i<N;++i) {
        if(q.empty() or q.top().first >= get<0>(Nums[i])) {
            q.push(make_pair(get<1>(Nums[i]), q.size()+1));
            rec[get<2>(Nums[i])] = q.size();
        }
        else {
            auto tmp = q.top(); q.pop();
            q.push(make_pair(get<1>(Nums[i]), tmp.second));
            rec[get<2>(Nums[i])] = tmp.second;
        }
    }
    cout << q.size() << '\n';
    for(int i: rec) cout << i << ' ';
    cout << '\n';
    return 0;
}
