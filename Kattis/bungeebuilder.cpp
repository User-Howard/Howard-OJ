#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<int> Nums(N);
    stack<pair<int, int> > sta;
    for(int &i: Nums) cin >> i;
    int answer = 0;
    for(int i=0;i<N;++i) {
        if(sta.empty()) {
            sta.push(make_pair(Nums[i], Nums[i]));
        } else if(sta.top().first <= Nums[i]) {
            answer = max(answer, sta.top().first - sta.top().second);
            sta.push(make_pair(Nums[i], Nums[i]));
        } else {
            if(sta.top().second > Nums[i]) {
                sta.top().second = Nums[i];
            }
        }
    }
    while(not sta.empty()) sta.pop();
    for(int i=N-1;i>=0;--i) {
        if(sta.empty()) {
            sta.push(make_pair(Nums[i], Nums[i]));
        } else if(sta.top().first <= Nums[i]) {
            answer = max(answer, sta.top().first - sta.top().second);
            sta.push(make_pair(Nums[i], Nums[i]));
        } else {
            if(sta.top().second > Nums[i]) {
                sta.top().second = Nums[i];
            }
        }
    }
    // answer = max(answer, sta.top().first - sta.top().second);
    cout << answer << '\n';
    return 0;
}