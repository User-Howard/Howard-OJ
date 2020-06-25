#include<iostream>
#define MAXL 10000
#define MAXN 1200000000
using namespace std;


int main(void){
    int arr[MAXN], P, Q, R, N;
    scanf("%d%d%d%d%d%d", &P, &Q, &R, &arr[0], &arr[1], &N);
    for(int i=2;i!=N+1;i++)
        arr[i]=(P*arr[i-1] +Q*arr[i-2] +R)%MAXL;
    printf("%d\n", arr[N]);
}
