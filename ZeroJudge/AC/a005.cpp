#include<iostream>
using namespace std;


int main(void)
{
    int count,a[4]={0};
    scanf("%d",&count);
    while(count--)
    {
        cin>>a[0]>>a[1]>>a[2]>>a[3];
        cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" ";
        if( (a[1]-a[0])==(a[2]-a[1]))
        {
            printf("%d\n",a[3]+a[1]-a[0]);
        }
        else
        {
            printf("%d\n",a[3]*a[1]/a[0]);
        }
    }
    return 0;
}
