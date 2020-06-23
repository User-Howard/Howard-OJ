#include<stdio.h>
#include<iostream>

int N;
int count, p;
char rest;


int main(void){
    scanf("%d",&N);
    getchar();
    while(N--){
        count = 0;
        p=0;
        while((rest=getchar())!='\n'){
            if(rest == 'p'){
                p++;
            }
            else if(rest == 'q'){
                if(p){
                    count++;
                    p--;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
