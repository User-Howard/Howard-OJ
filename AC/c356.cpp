#include<iostream>
using namespace std;


int main(void)
{
	int a=0;
	scanf("%d",&a);
	int count=a*a;
	char ch;
	getchar();
	for(int i=0;i<count;i++){
		ch=getchar();
		if(i%(a + 1) == 0)
			printf("%c",ch);
	}
	printf("\n");
	return 0;
}