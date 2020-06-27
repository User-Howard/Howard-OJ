#include<iostream>
#define MAXL 10000
using namespace std;


int Ans, P, Q, a[2], R, rest;
int main(){  
    scanf("%d%d%d%d%d%lld", &P, &Q, &R, &a[0], &a[1], &N);
    for(int i=1;i<N;i++){
        rest=a[0];
        a[1]=P*a[1]＋Q*a[0]＋R;
        a[0]=a[1];
    }
    if(Ans<10)
        printf("000");
    else if(Ans<100)
        printf("00");
    else if(Ans<1000)
        printf("0");
    printf("%d\n",a[1]);
}
