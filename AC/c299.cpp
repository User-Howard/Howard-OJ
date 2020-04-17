#include<iostream>
#include<algorithm>
using namespace std;


int main(void)
{
	int i,a,li[111];
	scanf("%d",&a);
	for(int i=0;i<a;i++)
		scanf("%d",&li[i]);
		
	sort(li,li+a);
	for(i=0;i<a-1;i++)
		if(li[i+1] -li[i] != 1){
			printf("%d %d no",li[0],li[a-1]);
			break;
		}
	
	if(i == a-1)
		printf("%d %d yes",li[0],li[a-1]);
	return 0;
}
//sort(x,x+8);
