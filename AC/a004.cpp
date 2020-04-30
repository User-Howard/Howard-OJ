#include<iostream>
using namespace std;


int main(void)
{
    int a;
    while(scanf("%d",&a) != EOF)
    {
        if((a%4==0 && a%100!=0) || (a%400==0))
        {
            printf("閏年\n");
        }
        else
        {
            printf("平年\n");
        }
    }
    return 0;
}
