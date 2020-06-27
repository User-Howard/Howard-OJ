#include<iostream>
#define MAXL 10000
#define MAXN 1200000000
using namespace std;


int P, Q, a1, a2, R, N;
int bbvc(int i, int j, int x){
    if(x==N)
        return (i+j)%MAXL;
    else
        return bbvc(j, (i+j)%MAXL, x+1);
int main(void){
   
    scanf("%d%d%d%d%d%d", &P, &Q, &R, &a1, &a2, &N);
    printf("%d\n", bbvc());
}
