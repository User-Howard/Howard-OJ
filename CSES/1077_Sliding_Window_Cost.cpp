#include <iostream>
#include <algorithm>
#include <set>
#include <assert.h>
using namespace std;

struct MedianSets {
    multiset<int> L, R;
    int64_t L_sum = 0, R_sum = 0;
    void insert(int x) {
        if (L.empty() or x <= *prev(L.end())) {
            L.insert(x);
            L_sum += x;
        }
        else {
            R.insert(x);
            R_sum += x;
        }
    }
    void erase(int x) {
        if (x <= *prev(L.end())) {
            L.erase(L.find(x));
            L_sum -= x;
        }
        else {
            R.erase(R.find(x));
            R_sum -= x;
        }
    }
    void balence() {
        while (L.size() > R.size()) {
            R_sum += *prev(L.end());
            L_sum -= *prev(L.end());
            R.insert(*prev(L.end()));
            L.erase(prev(L.end()));

        }
        while (L.size() < R.size()) {
            L_sum += *R.begin();
            R_sum -= *R.begin();
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
        int64_t answer = 0LL +  Sets.get_Median()*(Sets.L.size()-Sets.R.size()) \
                                - Sets.L_sum + Sets.R_sum;
        if(N <= i+1)
            cout << answer << ' ';
    }
    cout << '\n';

    return 0;

}
