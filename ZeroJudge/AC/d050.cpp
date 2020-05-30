#include<iostream>
using namespace std;


int main(void){
    int N;
    while(scanf("%d",&N) == 1){
        printf("%d\n",(N+9)%24);
    }
    return 0;
}