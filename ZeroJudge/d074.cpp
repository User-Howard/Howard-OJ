#include<iostream>
using namespace std;


int main(void)
{
	int N,r,max=0;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&r);
		if(max<r)
			max=r;
	}
	printf("%d",max);
	return 0;
}
