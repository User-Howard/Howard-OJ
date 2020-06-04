#include <bits/stdc++.h>
using namespace std;

int p[50005];

int root(int n)
{
    if (p[n] == n)
        return n;
    else
        return p[n] = root(p[n]);
}

int main()
{
    int n, m, religion, cnt = 1;
    while (cin >> n >> m)
    {
        if (!n && !m)
            break;

        religion = n;
        for (int i = 1; i <= n; i++)
            p[i] = i;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            if (root(a) != root(b))
            {
                p[root(a)] = root(b);
                religion--;
            }
        }
        printf("Case %d: %d\n", cnt++, religion);
    }
}
