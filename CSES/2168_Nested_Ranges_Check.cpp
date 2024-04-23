// https://www.geeksforgeeks.org/cses-solutions-nested-ranges-check/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Range {
    int l, r;
    int n;
    Range(){;}
    bool operator<(const Range& other) const {
        if(l != other.l) return l < other.l;
        else             return r > other.r;
    }
};
int main() {
    int N;
    cin >> N;
    vector<Range> Ranges(N);
    for(int i=0;i<N;++i) {
        Ranges[i].n = i;
        cin >> Ranges[i].l >> Ranges[i].r;
    }
    sort(Ranges.begin(), Ranges.end());
    vector<vector<int> > Answer(2, vector<int>(N));
    /*
    for(auto i: Ranges) {
        cout << i.l << ' ' << i.r << ' ' << i.n << '\n';
    }
    */
    int min_end =2e9 + 10;
    for(int i=N-1;i>=0;--i) {
        if(min_end <= Ranges[i].r) {
            Answer[0][Ranges[i].n] = 1;
        }
        min_end = min(min_end, Ranges[i].r);
    }
    int max_end = -1;
    for(int i=0;i<N;++i) {
        if(Ranges[i].r <= max_end) {
            Answer[1][Ranges[i].n] = 1;
        }
        max_end = max(max_end, Ranges[i].r);
    }
    for(int i=0;i<2;++i) {
        for(int j=0;j<N;++j) {
            cout << Answer[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
