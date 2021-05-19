#include<iostream>
using namespace std;


int main(void)
{
	int N,count=0,now;
	
	
	
	while(scanf("%d",&N) != EOF)
	{	
		now=1;
		for(int i=0;i<N;i++)
		{
			if(i%2 == 0)
			{
				for(int j=0;j<N;j++)
				{
					printf("%d ",now+j);
				}
				now+=N;
			}
			else
			{
				for(int j=N-1;j>=0;j--)
				{
					printf("%d ",now+j);
				}
				now+=N;
			}
			
			printf("\n");

		}
		printf("\n");
	}
	return 0;
}
