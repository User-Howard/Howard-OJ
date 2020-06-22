#include<stdio.h>
#include<iostream>
using namespace std;


int N;
string str;
int countl(char );


int main(void){
    scanf("%d", &N);
    getchar();
    while(N--){
        getline(cin, str);
        cout<<countl();    
    }
    return 0;
}
int countl(char c){
    int sum=0;
    for(int i=0;i<str.size();i++){
        sum+=str[i]==c;
    }
    return sum;
}
