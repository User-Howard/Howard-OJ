#include<stdio.h>
#include<iostream>
using namespace std;


int N;
string str;
bool solve(string str){
    if(( countl(str, '[') != countl(str, ']') ) or ( countl(str, '(') != countl(str, ')') )){
        return 0;
    }
    else{
        int smc=0, bic=0;
        for(int i=0;i<str.size();i++){
            if(str[i] == '('){
                string rest = cut(str, i+1, n_find(str, i+1, ')'));
                if(countl(rest, '[')!=countl(rest, ']'))
                    return 0;
                smc++;
            }
            else if(str[i] == ')')
                smc--;
            else if(str[i] == '['){
                string rest = cut(str, i+1, n_find(str, i+1, ']'));
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
    }
}
int countl(string str, char c){
    int sum=0;
    for(int i=0;i<str.size();i++){
        sum+=(str[i]==c);
    }
    return sum;
}
int n_find(string str, int latt, char c){
    for(int i=latt;i<str.size();i++){
        if(str[i] == c){
            return i;
        }
    }
    return -1;
}
string cut(string str, int x, int y){
    string RET="";
    for(int i=x;i<y;i++){
        RET+=str[i];
    }
    return RET;
}

int main(void){
    scanf("%d", &N);
    getchar();
    while(N--){
        getline(cin, str);
        solve(str);
    }
    return 0;
}
