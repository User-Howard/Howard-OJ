#include <iostream>
#include <stack>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> Pi;
#pragma GCC optimize("Ofast")
#define PB push_back
#define MP make_pair
#define ff first
#define ss second

struct Node
{
    LL h, l, c;
    Node(LL h_, LL l_, LL c_)
    {
        h = h_, l = l_, c = c_;
    }
};

int main()
{
    int N;
    LL h, ans = -1;
    stack<Node> s;
    cin >> N;
    s.push(Node(0, 0, 0)); // h l c
    for (LL c = 1; c <= N; ++c)
    {
        cin >> h;
        while (s.top().h >= h)
        {
            Node p = s.top();
            s.pop();
            ans = max(ans, p.h * (c - p.l));
        }
        s.push(Node(h, s.top().c + 1, c));
    }
    while (s.top().h > 0)
    {
        Node p = s.top();
        s.pop();
        ans = max(ans, p.h * (N - p.l + 1));
    }
    cout << ans << "\n";
}