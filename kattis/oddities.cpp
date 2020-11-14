#include<iostream>
#include<algorithm>
#define FOR(i, x) for(int i=0;i<x;i++)
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, temp;
    scanf("%d", &N);
    FOR(i, N){
        scanf("%d", &temp);
        printf("%d is %s\n", temp, abs(temp)%2? "odd":"even");
    }
    return 0;
}