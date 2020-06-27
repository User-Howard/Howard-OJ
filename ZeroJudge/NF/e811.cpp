#include<iostream>
#define MAXL 10000
using namespace std;


int P, Q, a[2], R, N;
int bbvc(int i, int j, int x){
    if(x==N+1)
        return j;
    else
        return bbvc(j, (P*j+Q*i+R)%MAXL, x+1);
}
int main(){  
    scanf("%d%d%d%d%d%d", &P, &Q, &R, &a[0], &a[1], &N);
    printf("%d\n", N<2? a[N] : bbvc(a[0], a[1], 2) );
    
}
