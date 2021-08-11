#include <iostream>
using namespace std;


int main(){
    int N;
    uint64_t nums[52] = {0, 1};
    for(int i = 2;i <= 50 ; ++i)
        nums[i] = nums[i-1] + nums[i-2];
    cin >> N;
    cout << nums[N] << '\n';
    return 0;
}