#include <stdio.h>
#include <iostream>
using namespace std;

int N;
char Str[26];
void dfs(int, int, int);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N)
    {
        dfs(0, 0, 0);
        cout << endl;
    }
    return 0;
}
void dfs(int now, int R, int L)
{
    if (now == N * 2 && R == L)
    {
        for (int i = 0; i < 2 * N; i++)
            printf("%c", Str[i]);
        printf("\n");
        return;
    }
    if (R <= N)
    {
        Str[now] = '(';
        dfs(now + 1, R + 1, L);
    }
    if (R >= L and L <= N)
    {
        Str[now] = ')';
        dfs(now + 1, R, L + 1);
    }
    return;
}
/*
1
2
3
4
4
5

*/
