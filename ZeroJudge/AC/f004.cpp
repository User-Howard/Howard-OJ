#include<stdio.h>

int main()
{
	int N=0,T=0;
	scanf("%d%d",&N,&T);
	int ans=0;
	if(N!=1)
	{
		T/=N;
		N/=N;
	}
	int temp=T+N;
	while(temp!=1)
	{
		temp/=2;
		ans+=1;
	}
	printf("%d\n",ans);
}