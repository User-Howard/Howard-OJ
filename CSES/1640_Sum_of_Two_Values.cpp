#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
 
int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    map<int, int> mp;
    
    for (int i = 0; i<N; i++) {
        cin >> A[i];
        if (mp.count(X - A[i])) {
            cout << mp[X - A[i]] << " " << i + 1 << endl;
            return 0;
        }
        mp[A[i]] = i + 1;
    }
    
    cout << "IMPOSSIBLE" << endl;
    return 0;
}