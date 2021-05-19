#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;


const int MAX_N = 2e5;
const int INF = 0x3f3f3f3f;
int N;
pair<int, int> arr [MAX_N + 2];
int above_amount [MAX_N + 2];
int get_above_amount(int it) {
    if (above_amount [it] != -INF)
        return above_amount [it];
    else {
        int MAX = 0;
        for (int i = it + 1;i < N;i++) {
            if (arr [i].second < arr [it].second)
                continue;
            MAX = max(get_above_amount(i) + 1, MAX);
        }
        return above_amount [it] = MAX;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0;i < N;i++)
        cin >> arr [i].first >> arr [i].second;
    arr [N++] = make_pair(0, 0);

    sort(arr, arr + N);
    fill(above_amount, above_amount + N, -INF);

    cout << get_above_amount(0) << '\n';
    return 0;
}