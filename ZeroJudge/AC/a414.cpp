#include <iostream>
using namespace std;

int main(void)
{
    int a;
    while (scanf("%d", &a) && a != 0)
    {
        
        int i=0;
        while(a%2)
        {
            i++;
            a/=2;
        }
        printf("%d\n",i);
    }
    return 0;
}