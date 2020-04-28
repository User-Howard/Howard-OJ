#include<iostream>
#include<vector>
using namespace std;

int MONEY[7]={1000,500,100,50,10,5,1};
vector<int > ale(7);

int main(void)
{
	int N;
	while(scanf("%d",&N)){
		ale.clear();
		for(int i=0;i<7;i++)
		{
			while(N>=MONEY[i])
			{
				cout<<N<<" "<<MONEY[i]<<endl;
				ale[i]++;
				N-=MONEY[i];
			}
		}
		for(int i=0;i<7;i++)
		{
			if(ale[i] != 0)
				printf("%d*%d ",MONEY[i],ale[i]);
		}
		printf("\n");
	}
	return 0;
}
/*
1じ
5じ
10じ
50じ
100じ
500じ
1000じ
*/
