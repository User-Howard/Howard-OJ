#include<iostream>
#include<algorithm>
using namespace std;


int main(void)
{
	int N, li[(int)1e2+2];
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&li[i]);
		
	sort(li,li+N);
	for(int i=0;i<N-1;i++)
		if(li[i+1] -li[i] != 1){
			printf("%d %d no",li[0],li[N-1]);
			goto final;
		}	
	printf("%d %d yes",li[0],li[N-1]);
	
final:
	return 0;
}
//sort(x,x+8);
