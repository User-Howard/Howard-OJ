#include <iostream>
using namespace std;

int main(void)
{
    string a;
    cin >> a;
    int b = 0, r = a.length() -1;
    for (;r >= 0;r--)
    {
        b = b * 10 + (int)a[r] - 48;
    }
    printf("%d", b);

    return 0;
}