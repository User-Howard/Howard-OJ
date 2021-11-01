#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int nums[5000];
    while(cin >> N and N){
        priority_queue<int, vector<int>, greater<int> >pqr;
        unsigned int cost = 0;
        for(int i=0;i<N;++i)
            cin >> nums[i], pqr.push(nums[i]);
        for(int i=1;i<N;++i){
            int m = pqr.top();pqr.pop();
            int n = pqr.top();pqr.pop();
            pqr.push(m + n);
            cost += m + n;
        }
        cout << cost << '\n';
    }
    return 0;
}