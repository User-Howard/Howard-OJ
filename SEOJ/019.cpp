#include <iostream>
#include <stack>
using namespace std;


int T;
int N;
int nums[(int)1e5+2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i=0;i<N;++i)
            cin >> nums[i];
        stack<int> sta;
        int pointer = 0;
        for(int i=0;i<N;++i){
            if(!sta.empty() and nums[i] == sta.top()){
                sta.pop();
                // cout << "A\t";
            }
            else if(nums[i] > pointer){
                for(int j=pointer+1;j<nums[i];++j)
                    sta.push(j);
                pointer = nums[i];
                // cout << "B\t";
            }
            else if(nums[i] < pointer){
                cout << "No" << '\n';
                goto END;
            }
        }
        // cout << '\n';
        cout << "Yes" << '\n';
        END:;
    }
    return 0;
}