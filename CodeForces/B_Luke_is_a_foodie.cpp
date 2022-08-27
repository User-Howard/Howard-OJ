#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <numeric>
using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

int solve() {
    int N, X;
    cin >> N >> X;
    vi nums(N);
    for(int i=0;i<N;++i)
        cin >> nums[i];
    int pointer = 1;
    int min_ele, max_ele, ans = 0;
    min_ele = max_ele = nums[0];
    while(pointer < N) {
        min_ele = min(nums[pointer], min_ele);
        max_ele = max(nums[pointer], max_ele);
        if(max_ele - min_ele > 2*X) {
            min_ele = max_ele = nums[pointer];
            ++ans;
        }
        pointer++;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cout << solve() << '\n';
    }
    return 0;
}