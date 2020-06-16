#include<iostream>
using namespace std;


int N, now;

int find(string, int);
int main(void){
    while(scanf("%d", &N) != EOF){
        cout<<"(";
        now=1;
        find("", N-1);
        cout<<endl;
    }
    
    return 0;
}
int find(stack<char> output, int less){
    if(less == 0)
        return 0;
    
}
