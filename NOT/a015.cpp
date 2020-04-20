#include<iostream>
using namespace std;


int main(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	int arr[a][b];
	for(int i=0;i<b;i++)
		for(int j=0;j<a;j++)
			scanf("%d",arr[i][j]);
			
			
	
	return 0;
}
