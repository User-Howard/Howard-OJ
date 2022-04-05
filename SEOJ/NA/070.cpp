#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        priority_queue<uint64_t , vector<uint64_t>, greater<uint64_t> > prque;
        while(N--){
            int num;
            cin >> num;
            prque.push(num);
        }
        uint64_t ans = 0;
        while(prque.size() != 1){
            uint64_t a = prque.top(); prque.pop();
            uint64_t b = prque.top(); prque.pop();
            ans += a + b;
            prque.push(a + b);
        }
        cout << ans << '\n';
    }
    return 0;
}