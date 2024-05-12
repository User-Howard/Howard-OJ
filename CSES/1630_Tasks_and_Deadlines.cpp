#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
    int N;
    cin >> N;
    vector<pair<int, int> > Tasks(N);
    for(auto &i: Tasks) {
        cin >> i.first >> i.second;
    }
    sort(Tasks.begin(), Tasks.end());
    int64_t answer = 0;
    int64_t pointer = 0;
    for(auto task: Tasks) {
        pointer += task.first;
        answer += task.second - pointer;
    }
    cout << answer << '\n';
    return 0;
}
