#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b)
{
    if (a[1] != b[1])
        return a[1] < b[1];
    else
        return a[0] < b[0];
}
vector<string> h19 = {"1m", "9m", "1p", "9p", "1s", "9s", "1z", "2z", "3z", "4z", "5z", "6z", "7z"};
vector<string> h49 = {"4m", "9m", "4p", "9p", "4s", "9s", "1z", "2z", "3z", "4z", "5z", "6z", "7z"};
string solve()
{
    vector<string> R(14);
    for (string &i : R)
        cin >> i;
    sort(R.begin(), R.end(), cmp);
    R.resize(distance(R.begin(), unique(R.begin(), R.end())));
    if (R == h19)
        return "19";
    else if (R == h49)
        return "49";
    else
        return "QwQ";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cout << solve() << '\n';
    }
    return 0;
}