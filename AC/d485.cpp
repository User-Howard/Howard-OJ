#include<iostream>
using namespace std;


int main(void)
{
    int xa,xb;
    scanf("%d %d",&xa,&xb);

    printf("%d\n",(xb/2)-(xa/2) +(xa%2 ? 0 :1));
    return 0;
}