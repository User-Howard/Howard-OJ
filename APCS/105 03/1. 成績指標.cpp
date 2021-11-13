#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int N;
    vector<int> nums;
    cin >> N;
    nums.resize(N);
    for(int i=0;i<N;++i)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    for(int i=0;i<N;++i)
        cout << nums[i] << ' ';
    cout << endl;
    vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), 60);
    if(it == nums.begin())
        cout << "best case" << endl;
    else
        cout << *(it-1) << endl;
    if(it == nums.end())
        cout << "worst case" << endl;
    else
        cout << *(it) << endl;
    return 0;
}