#include<iostream>
using namespace std;

int aad(int a){
	if(a == 1)
		return 2;
	else if(a == 2)
		return 4;
	else if(a == 3)
		return 8;
		
	return 2*(a-1) + aad(a-1);
}

int main(void)
{
	int a;
	while(scanf("%d",&a) != EOF)
		printf("%d\n",aad(a));
	
	return 0;
}
