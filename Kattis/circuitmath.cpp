#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<char> C(N+2, 'F');
    for(int i=0;i<N;++i) {
        cin >> C[i];
    }
    C[N+1] = 'T';
    char c;
    stack<char> sta;
    while(cin >> c) {
        if(c == '*') {
            char a = sta.top(); sta.pop();
            char b = sta.top(); sta.pop();
            bool t = C[a-'A'] == 'T' and C[b-'A'] == 'T';
            sta.push('A'+N+t);
        } else if(c=='+') {
            char a = sta.top(); sta.pop();
            char b = sta.top(); sta.pop();
            bool t = C[a-'A'] == 'T' or C[b-'A'] == 'T';
            sta.push('A'+N+t);

        } else if(c=='-') {
            char a = sta.top(); sta.pop();
            bool t = C[(a-'A')] != 'T';
            sta.push('A'+N+t);
        } else {
            sta.push(c);
        }
    }
    cout << C[sta.top()-'A'] << '\n';
    
    return 0;
}