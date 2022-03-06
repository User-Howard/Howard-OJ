#include <iostream>
#include <queue>
using namespace std;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    queue<int> que;
    cin >> T;
    while(T--){
        int a, b;
        cin >> a;
        if(a == 1){
            cin >> b;
            que.push(b);
        }
        else{
            if(que.empty()){
                cout << "empty!" << '\n';
            }
            else{
                cout << que.front() << '\n';
                que.pop();
            }
        }
    }
    return 0;
}