#include<stdio.h>
#include<iostream>
using namespace std;


int W, H;
char arr[102][22];
string rest;


int dfs(int h, int N){
    if(h==H)
        return N;
    else if(N!=0 and arr[h][N-1]=='-')
        return dfs(h+1, N-2);
    else if(N!=W*2-2 and arr[h][N+1]=='-')
        return dfs(h+1, N+2);
    else
        return dfs(h+1, N  );
}


int main(void){
    while(scanf("%d %d", &W, &H) == 2){
        getchar();
        for(int i=0;i<H;i++){
            getline(cin, rest);
            for(int j=0;j<W*2-1;j++){
                arr[i][j]=rest[j];
            }
        }
        for(int i=0;i<W*2-1;i+=2)
            printf("%d ", dfs(0, i)/2+1);
        puts("");
    }
    return 0;
}
