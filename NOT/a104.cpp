#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int len;
    while (scanf("%d", &len) != EOF)
    {
        //ADD list
        int v[] = {};
        for (int i = 0; i < len; i++)
            scanf("%d", v[i]);

        sort(v, v + len);

        for (int i = 0; i < len; i++)
            printf("%d ", v[i]);
        printf("\n");
    }
    return 0;
}
