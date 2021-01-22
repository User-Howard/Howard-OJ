
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
int main(){
    int N;
    ll answer;
    ll t;
    priority_queue<ll, vector<ll>, greater<ll> > que;
    while (cin >> N){
        answer = 0;
        for (int i = 0 ; i < N;++i){
            cin >> t;
            que.push(t);
        }

        while (que.size() > 1){
            ll t1 = que.top();
            que.pop();
            ll t2 = que.top();
            que.pop();
            
            ll cur_sum = t1 + t2;
            answer += cur_sum;
            que.push(cur_sum);
        }
        cout << answer << endl;
    }
    return 0;
}