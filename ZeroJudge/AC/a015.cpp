#include<iostream>
using namespace std;


int main(void)
{
	int a,b;
	while(scanf(" %d %d",&a,&b) != EOF){
	
		int arr[102][102];
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				scanf("%d",&arr[i][j]);
	
	
		for(int i=0;i<b;i++)
		{
			for(int j=0;j<a;j++)
				printf("%d ",arr[j][i]);
			printf("\n");
		}
	
	}
	return 0;
}
