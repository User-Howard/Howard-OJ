#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N;
vector<int>nums;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    nums.resize(N);
    for(int i=0;i<N;i++)
        cin >> nums[i];
    sort(nums.begin(),nums.end());
    for(int i=0;i<N;i++)
        cout << nums[i] << ' ';
    cout << '\n';
    return 0;
}