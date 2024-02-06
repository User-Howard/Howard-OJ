#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        times.push_back({a, 1});
        times.push_back({b, -1});
    }

    sort(times.begin(), times.end());

    int current = 0, maxCustomers = 0;
    for (const auto& time : times) {
        current += time.second;
        maxCustomers = max(maxCustomers, current);
    }

    cout << maxCustomers << endl;

    return 0;
}