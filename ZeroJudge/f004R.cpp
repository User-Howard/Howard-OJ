#include<iostream>
#include<vector>
using namespace std;

int MONEY[7]={1000,500,100,50,10,5,1};
vector<int > ale(7,0);



int main(void)
{
	int N,rest;
	while(scanf("%d",&N) != EOF){
		
		rest=N;
		
		for(int i=0;i<7;i++)
			ale[i]=0;
		
		for(int i=0;i<7;i++)
		{
			while(rest>=MONEY[i])
			{
				ale[i]++;
				rest-=MONEY[i];
				//cout<<N<<" "<<MONEY[i]<<endl;
			}
		}
		
		int r=0;
		for(int i=0;i<7;i++)
			if(ale[i] != 0)
				r++;
		
		printf("%d = ",N);
		
		for(int i=0;i<7;i++)
		{
			if(ale[i] != 0)
			{
				printf("%d*%d ",MONEY[i],ale[i]);
				r--;
				if(r >= 1)
				{
					printf("+ ");
			
				}

			}
				
				
		}
		printf("\n");
	}
	return 0;
}
/*
1?¡M
5?¡M
10?¡M
50?¡M
100?¡M
500?¡M
1000?¡M
*/
