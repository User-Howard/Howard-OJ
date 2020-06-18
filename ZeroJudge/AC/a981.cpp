#include <stdio.h>
#include <iostream>
using namespace std;


int N;
char Str[30];
void dfs(int, int, int);


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N)
    {
        dfs(0, 0, 0);
        cout << endl;
    }
    return 0;
}
void dfs(int now, int L, int R)
{
    if (now == N * 2 && R == L)
    {
        printf("%s\n", Str);
        return;
    }
    if (L < N){
        Str[now] = '(';
        dfs(now + 1, L + 1, R);
    }
    if (L > R and L <= N){
        Str[now] = ')';
        dfs(now + 1, L, R + 1);
    }
    return;
}
