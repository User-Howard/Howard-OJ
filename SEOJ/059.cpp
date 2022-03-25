#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(){
    int N, si, sj;
    cin >> N;
    priority_queue<int, vector<int>, greater<int> > prique;
    while(N--){
        cin >> si;
        if(si == 1){
            cin >> sj;
            prique.push(sj);
        }
        else{
            if(prique.empty())
                cout << "empty!\n";
            else{
                cout << prique.top() << '\n';
                prique.pop();
            }
        }
    }
    return 0;
}