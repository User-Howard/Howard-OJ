#include <stdio.h>


int N;
char Str[30];
void dfs(int, int, int);


int main(){
    while (scanf("%d",&N) != EOF)
    {
        dfs(0, 0, 0);
        puts("");
    }
    return 0;
}
void dfs(int now, int L, int R){
    if (now == N * 2 && R == L){
        puts(Str);
        return;
    }
    if (L < N){
        Str[now] = '(';
        dfs(now + 1, L + 1, R);
    }
    if (L > R && L <= N){
        Str[now] = ')';
        dfs(now + 1, L, R + 1);
    }
    return;
}
