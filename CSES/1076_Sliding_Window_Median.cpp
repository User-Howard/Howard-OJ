#include <iostream>
#include <algorithm>
#include <set>
#include <assert.h>
using namespace std;

struct MedianSets {
    multiset<int> L, R;
    void insert(int x) {
        if (L.empty() or x <= *prev(L.end())) {
            L.insert(x);
        }
        else {
            R.insert(x);
        }
    }
    void erase(int x) {
        if (x <= *prev(L.end()))
            L.erase(L.find(x));
        else
            R.erase(R.find(x));
    }
    void balence() {
        while (L.size() > R.size()) {
            R.insert(*prev(L.end()));
            L.erase(prev(L.end()));
        }
        while (L.size() < R.size()) {
            L.insert(*R.begin());
            R.erase(R.begin());
        }
    }
    int get_Median() {
        assert(L.size()==R.size() or L.size()==R.size()+1);
        return *prev(L.end());
    }
};
int main() {
    int K, N;
    cin >> K >> N;
    MedianSets Sets;
    vector<int> Nums(K);
    for(int &i: Nums) cin >> i;
    for (int i=0;i<K;++i) {
        Sets.insert(Nums[i]);
        if (N <= i)
            Sets.erase(Nums[i-N]);
        Sets.balence();
        if(N <= i+1)
            cout << Sets.get_Median() << ' ';
    }
    cout << '\n';

    return 0;
}
