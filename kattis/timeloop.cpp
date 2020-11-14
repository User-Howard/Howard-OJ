#include<iostream>
#define FOR(i, x) for(int i=0;i<x;i++)
using namespace std;


int main(void){
    int N;
    scanf("%d", &N);
    FOR(i, N){
        printf("%d Abracadabra\n", i+1);
    }
    return 0;
}