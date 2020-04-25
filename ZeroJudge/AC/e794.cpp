#include<iostream>
using namespace std;


int main(void)
{
	int times;
	while(scanf("%d",&times))
	{
		int li[times];
		li[0]=1;
		li[1]=2;
		for(int cn=2;cn<times;cn++)
		{
			li[cn]=li[cn-1]+li[cn-2];
		}
		printf("%d:%d\n",li[times-2],li[times-1]);
	}
	
    return 0;
}


