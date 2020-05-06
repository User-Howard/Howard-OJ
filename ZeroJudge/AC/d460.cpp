#include<iostream>
using namespace std;


int main(void){
	int y;
	scanf("%d",&y);
	if(y<6)
		printf("0\n");
	else if(y<12)
		printf("590\n");
	else if(y<18)
		printf("790\n");
	else if(y<60)
		printf("890\n");
	else
		printf("399\n");
	return 0;
}
