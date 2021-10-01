#include <iostream>
using namespace std;


const int MAX_N = 1e6;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    int nums[MAX_N];

    while(cin >> T){
        for(int i=0;i<T;++i)
            cin >> nums[i];

        int64_t sum_num = 0, sum_d = 0;
        for(int i=0;i<T;++i){
            sum_num += nums[i];
            sum_d += nums[i]*nums[i];
        }
        cout << (sum_num*sum_num - sum_d) / 2 << '\n';

    }
    return 0;
}
