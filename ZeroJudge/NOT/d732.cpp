#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int main(void)
{
    int n, k, val;
    map<int, int>arr;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &val);
        arr.insert(pair<int, int>(val, i));
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &val);
        printf("%d\n", val>0 ? arr[val] : 0);
    }
    return 0;
}
