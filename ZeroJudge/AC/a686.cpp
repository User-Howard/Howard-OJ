#include<iostream>
using namespace std;


int main(void)
{
	int x,y,z,times;
	scanf("%d",&times);
	for(;times>=1;times--)
	{
		cin>>x>>y>>z;
		int days=1;
		bool run=true;

		if(y-z>0 || x-y<0)
		{
			while(run)
			{
				x-=y;
				if(x<=0)
				{
					printf("%d\n",days);
					run=false;
				}
				x+=z;
				days+=1;
			}
		}
		else{
			printf("Poor Snail\n");
		}
	}
	return 0;
}
