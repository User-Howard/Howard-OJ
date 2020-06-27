#include<iostream>
#define MAXL 10000
using namespace std;


int Ans, P, Q, a[2], R;
long long int N;
int bbvc(int i, int j, long long int x){
    if(x==N+1)
        return j;
    else
        return bbvc(j, (P*j+Q*i+R)%MAXL, x+1);
}
int main(){  
    scanf("%d%d%d%d%d%lld", &P, &Q, &R, &a[0], &a[1], &N);
    Ans=N<2? a[N] : bbvc(a[0], a[1], 2);
    if(Ans<10)
        printf("000");
    else if(Ans<100)
        printf("00");
    else if(Ans<1000)
        printf("0");
    printf("%d\n",Ans);
}
