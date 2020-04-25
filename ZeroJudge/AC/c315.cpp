#include<iostream>
using namespace std;


int main(void)
{
	int li[2]={0,0},y=0,count;
	int x=0;
	scanf("%d",&count);
	while(count--)
	{
		scanf("%d%d",&x,&y);
		if(x==0)
			li[1]+=y;
		else if(x==1)
			li[0]+=y;
		else if(x==2)
			li[1]-=y;
		else if(x==3)
			li[0]-=y;
	}
	printf("%d %d\n",li[0],li[1]);
	return 0;
}
