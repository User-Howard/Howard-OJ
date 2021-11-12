#include <bits/stdc++.h>
#define StarBurstStream               \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define eb emplace_back
using namespace std;

int main()
{
    StarBurstStream int n,
        m;
    cin >> n >> m;
    vector<vector<int> > g(n + 1);
    vector<int> deg(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        deg[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
        int now = q.front();
        ans.eb(now);
        q.pop();
        for (int i : g[now])
        {
            deg[i]--;
            if (deg[i] == 0)
                q.push(i);
        }
    }

    if (ans.size() != n)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}