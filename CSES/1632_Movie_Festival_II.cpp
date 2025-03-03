#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set> 
using namespace std;
 
 
bool operator<(pair<int, int> &a, pair<int, int> &b) {
    if(a.second==b.second)  return a.first < b.first;
    else                    return a.second < b.second;
}
int main() {
    int K, N;
    cin >> K >> N;
    vector<pair<int, int> > Movies(K);
    for(auto &i: Movies) cin >> i.first >> i.second;
    sort(Movies.begin(), Movies.end());
    multiset<int> pq;
    for(int i=0;i<N;++i)
        pq.insert(i);
    int answer = 0;
    for(int i=0;i<K;++i) {
        auto lastPerson = pq.upper_bound(Movies[i].first);
        if(lastPerson==pq.begin()) continue;
        lastPerson--;
        if(Movies[i].first < *lastPerson) continue;
        pq.erase(lastPerson);
        pq.insert(Movies[i].second);
        ++answer;
    }
    cout << answer << '\n';
    return 0;
}