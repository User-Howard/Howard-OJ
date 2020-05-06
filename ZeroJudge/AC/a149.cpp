#include<iostream>
using namespace std;

int main(void)
{
    int a,r,sum;
    string c;
    scanf("%d",&a);
    while (a--)
    {
        sum=1;
        cin>>c;
        r=c.size();
        for(int i=0;i<r;i++)
        {
            sum*=c[i]-48;
        }
        printf("%d\n",sum);
    }
    
    
    return 0;
}