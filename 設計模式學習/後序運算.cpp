#include <iostream>
#include <vector>
#include <stack>
#include <windows.h>
using namespace std;


int weights(char c){
    switch(c){
    case '(':
        return -1;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
}
void solve(string &s){  
    vector<string> postfix;
    stack<char> sta;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            string sint = "";
            while(i<s.size() && isdigit(s[i])){
                sint += s[i];
                ++i;
            }
            --i;
            postfix.push_back(sint);
        }
        else if(s[i] != ' '){
            if(s[i] == '('){
                sta.push(s[i]);
            }
            else if(s[i] == ')'){
                while (sta.top()!='(')
                    postfix.push_back(string(1, sta.top())), sta.pop();
                sta.pop();
            }
            else{
                while(!sta.empty() && weights(sta.top()) > weights(s[i]))
                    postfix.push_back(string(1, sta.top())), sta.pop();
                sta.push(s[i]);
            }
        }
    }
    while(!sta.empty())
        postfix.push_back(string(1, sta.top())), sta.pop();
    for(string i:postfix)
        cout << i << ' ';
    cout << '\n';
    
}
int main(){
    string S;
    getline(cin, S);
    solve(S);
    return 0;
}