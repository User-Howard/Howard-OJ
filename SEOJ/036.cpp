#include <iostream>
#include <stack>
using namespace std;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    stack<int> sta;
    cin >> T;
    while(T--){
        int a, b;
        cin >> a;
        if(a == 1){
            cin >> b;
            sta.push(b);
        }
        else{
            if(sta.empty()){
                cout << "empty!" << '\n';
            }
            else{
                cout << sta.top() << '\n';
                sta.pop();
            }
        }
    }
    return 0;
}