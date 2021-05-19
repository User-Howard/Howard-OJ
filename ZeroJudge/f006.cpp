#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N,arr[102];
	scanf("%d",&N);
	for(int i=0;i<N;++i)
		scanf(" %d",&arr[i]);
	sort(arr,arr+N);
	printf("%d %d\n",arr[N-1],arr[0]);
	return 0;
}
