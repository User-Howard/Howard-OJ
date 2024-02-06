#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<pair<int, int> > T;
    for(int i=0;i<N;++i) {
        int a, b;
        cin >> a >> b;
        T.push_back(make_pair(b, a));
    }
    sort(T.begin(), T.end());
    int e=-1, answer=0;
    for(auto i: T) {
        if(i.first < e or i.second < e) continue;
        e = i.first;
        ++answer;
    }
    cout << answer << '\n';
    return 0;
}