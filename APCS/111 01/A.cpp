// AC
// https://zerojudge.tw/ShowProblem?problemid=h081
/*
1   0.8
2   1
*/
#include <iostream>
#include <vector>
using namespace std;


const int INF = 0x3f3f3f3f;
int main(){
    int N, D;
    cin >> N >> D;
    vector<int > nums(N);
    for(int &i:nums) cin >> i;
    int last_hold = INF, hold = -1;
    int answer = 0;
    for(int i:nums){
        if(hold == -1){
            if(i <= last_hold - D){
                hold = i;
            }
        }
        else if(hold + D <= i){
            answer += i - hold;
            last_hold = i; hold = -1;
        }
    }
    cout << answer << '\n';
    return 0;
}