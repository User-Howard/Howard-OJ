#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(){
    int T;
    priority_queue<int, vector<int>, greater<int> >prque;
    cin >> T;
    while(T--){
        int x, y;
        cin >> x;
        if(x == 1){
            cin >> y;
            prque.push(y);
        }
        else{
            if(prque.empty())
                cout << "empty!" << '\n';
            else{
                cout << prque.top() << '\n';
                prque.pop();
            }
        }
    }
    return 0;
}