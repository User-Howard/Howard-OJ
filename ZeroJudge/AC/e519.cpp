#include<iostream>
using namespace std;


int main(void)
{
  int a,m,n;
  while(scanf("%d",&a) && a != 0)
  {
    for(n=10;;n++,m=n/10)
    {
      if(m+a == n)
        printf("%d ",n);
      if(m+a <  n)
        break;
    }
    printf("\n");
  }printf("\n");

  return 0;
}
