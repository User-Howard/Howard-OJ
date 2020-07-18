#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;
int sta[10], p;
int ch(char c)
{
    switch (c)
    {
    case 'O':
        return 0;
    case 'X':
        return 1;
    case '-':
        return 2;
    }
}
int AC[3]; //O ?A??X ?A??????
set<int> s;
bool in()
{
    int t = 0, i;
    for (i = 0; i < 9; i++)
        t = t * 3 + sta[i];
    if (!s.count(t))
    {
        s.insert(t);
        return true;
    }
    else
        return false;
}
int ck()
{
    int i;
    bool f = true;
    for (i = 0; i < 9; i++)
        if (sta[i] == 2)
        {
            f = false;
            break;
        }
    for (i = 0; i < 3; i++)
        if (sta[i * 3] == sta[i * 3 + 1] && sta[i * 3 + 1] == sta[i * 3 + 2] && sta[i * 3] != 2)
            return sta[i * 3];
    for (i = 0; i < 3; i++)
        if (sta[i] == sta[i + 3] && sta[i + 3] == sta[i + 6] && sta[i] != 2)
            return sta[i];
    if (sta[0] == sta[4] && sta[4] == sta[8] && sta[4] != 2)
        return sta[0];
    if (sta[2] == sta[4] && sta[4] == sta[6] && sta[4] != 2)
        return sta[2];
    if (f)
        return 2;
    return -1;
}
void dfs()
{
    if (!in())
        return;
    int t = ck();
    if (t != -1)
    {
        for(int i=0;i<9;i++){
            printf("%d ", sta[i]);
            if(i%3 == 2)
                printf("\n");
        }
        printf("\n");

        AC[t]++;
        return;
    }
    int i;
    for (i = 0; i < 9; i++)
        if (sta[i] == 2)
            sta[i] = p, p = !p, dfs(), sta[i] = 2, p = !p;
}
int main()
{
    char s[10];
    scanf("%s", s);
    int i;
    for (i = 0; i < 9; i++)
        sta[i] = ch(s[i]);
    int t1 = 0, t2 = 0;
    for (i = 0; i < 9; i++)
        if (sta[i] == 0)
            t1++;
        else if (sta[i] == 1)
            t2++;
    if (t1 > t2)
        p = 1;
    else
        p = 0;
    dfs();
    printf("%d %d %d %d\n", AC[0] + AC[1] + AC[2], AC[0], AC[1], AC[2]);
    scanf(" ");
    return 0;
}