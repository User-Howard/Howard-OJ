#include <iostream>
using namespace std;

int N;
int nums[(int)1e5];
bool solve(){
    for(int i=1;i<N;i++)
        if(nums[i]!=nums[i-1])
            return false;
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> nums[i];
    if(solve())
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    return 0;
}
