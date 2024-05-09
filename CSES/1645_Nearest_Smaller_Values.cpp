#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


const int MAX_N =2e5 + 5;
int Nums[MAX_N];
int main() {
    int N;
    cin >> N;
    for(int i=0;i<N;++i)
        cin >> Nums[i];
    stack<pair<int, int> > sta;
    for(int i=0;i<N;++i) {
        while(not sta.empty() and sta.top().first >= Nums[i]) sta.pop();
        cout << (sta.empty() ? 0 : sta.top().second) << ' ';
        sta.push({Nums[i], i+1});
    }

    return 0;
}
