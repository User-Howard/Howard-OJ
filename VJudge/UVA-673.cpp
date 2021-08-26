#include <iostream>
#include <stack>
using namespace std;


bool is_correct(string &s){
    stack<char> sta;
    for(int i=0;i<s.size();++i){
        if((s[i] == '(' || s[i] == '['))
            sta.push(s[i]);
        else{
            if(sta.empty())
                return 0;
            if(s[i] == ')'){
                if(sta.top() == '(')
                    sta.pop();
                else
                    return 0;
            }
            if(s[i] == ']'){
                if(sta.top() == '[')
                    sta.pop();
                else
                    return 0;
            }
        }
    }
    return sta.empty();
}
int main(){
    int T;
    string S;
    getline(cin, S);
    cout << is_correct(S) << "<-\\\n";
    return 0;
}