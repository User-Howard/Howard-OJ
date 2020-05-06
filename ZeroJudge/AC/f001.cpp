#include<iostream>
using namespace std;


int main(void)
{
	int N,r,max=0,min=2147483647;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&r);
		
		if(max<r)
			max=r;
		if(r<min)
			min=r;
	}
	printf("%d %d",max,min);
	return 0;
}
