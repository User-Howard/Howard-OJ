#include<stdio.h>


int main(void){
    int N;

    while(scanf("%d",&N) != EOF){
        if(N==0)
            puts("0");
        else if(N > 0)
            puts("1");
        else
            puts("-1");
    }
    return 0;
}
