#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main(){
    int N;
    cin >> N;
    getchar();
    string S;
    getline(cin, S);
    stack<char> Sta;
    for(int i=0;i<N;++i) {
        cerr << S[i] << ' ' << i << '\n';
        if(S[i]=='(') {
            Sta.push('(');
        }
        if(S[i]=='[') {
            Sta.push('[');
        }
        if(S[i]=='{') {
            Sta.push('{');
        }
        if(S[i]==')') {
            if(Sta.empty() or Sta.top()!='(') {
                cout << ") " << i << '\n';
                goto END;
            } else {
                Sta.pop();
            }
        }
        if(S[i]==']') {
            if(Sta.empty() or Sta.top()!='[') {
                cout << "] " << i << '\n';
                goto END;
            } else {
                Sta.pop();
            }
        }
        if(S[i]=='}') {
            if(Sta.empty() or Sta.top()!='{') {
                cout << "} " << i << '\n';
                goto END;
            } else {
                Sta.pop();
            }
        }
    }
    cout << "ok so far\n";
    END:;
    return 0;
}