#include<stdio.h>
#include<iostream>
using namespace std;


int N;
string str;
bool solve(string);
string cut(string, int, int);
int countl(string, char);
int n_find(string, int, char); //字串, 從哪開始, 尋找字元


int main(void){
    scanf("%d", &N);
    getchar();
    while(N--){
        getline(cin, str);
        if(solve(str))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
bool solve(string str){
    if(( countl(str, '[') != countl(str, ']') ) or ( countl(str, '(') != countl(str, ')') )){
        return 0;
    }
    else{
        int smc=0, bic=0;
        for(int i=0;i<str.size();i++){
            if(str[i] == '('){
                string rest = cut(str, i, n_find(str, i+1, ')')+1);
                
                if(countl(rest, '[')!=countl(rest, ']'))
                    return 0;
                smc++;
            }
            else if(str[i] == ')')
                smc--;
            else if(str[i] == '['){
                string rest = cut(str, i, n_find(str, i+1, ']')+1);
                if(countl(rest, '(')!=countl(rest, ')'))
                    return 0;
                bic++;
            }
            else if(str[i] == ']')
                bic--;
            
            if(bic<0 or smc<0){
                return 0;
            }
            
        }
        return 1;
    }
}
string cut(string str, int x, int y){
    string RET="";
    for(int i=x;i<y;i++){
        RET+=str[i];
    }
    // cout<<RET<<endl;
    return RET;
}
int countl(string str, char c){
    int sum=0;
    for(int i=0;i<str.size();i++){
        sum+=(str[i]==c);
    }
    return sum;
}
int n_find(string str, int latt, char c){
    char another;
    if(c == ')')
        another = '(';
    else
        another = '[';
    int counter = 0;
    for(int i=latt;i<str.size();i++){
        if(str[i] == another){
            counter++;
        }
        if(str[i] == c){
            counter--;
        }
        if(counter == -1){
            return i;
        }
    }
    return -1;
}
