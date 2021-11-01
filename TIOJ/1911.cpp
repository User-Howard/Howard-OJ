#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    priority_queue<int, vector<int>, greater<int> >min_ele;
    priority_queue<int, vector<int>, less<int> >max_ele;
    unordered_map<int, uint64_t>ump;
    while(cin>>N && N){
        switch (N){
        case -2:
            while(max_ele.size() && !ump[max_ele.top()])
                max_ele.pop();
            
            cout << max_ele.top() << ' ';
            --ump[max_ele.top()];
            max_ele.pop();
            break;
        case -1:
            while(min_ele.size() && !ump[min_ele.top()])
                min_ele.pop();
            
            cout << min_ele.top() << ' ';
            --ump[min_ele.top()];
            min_ele.pop();
            break;
        default:
            min_ele.push(N);
            max_ele.push(N);
            if(ump.find(N) == ump.end())
                ump[N] = 0;
            ++ump[N];
            break;
        }
    }
    cout << '\n';
    return 0;
}