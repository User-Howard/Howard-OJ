#include<iostream>
using namespace std;


int main(void){
	int li[502]={1},N;
	for(int n=1;n<500;n++)
		li[n]=li[n-1]+n;
	
	while(scanf("%d",&N) != EOF){
		printf("%d\n",li[N-1]);
	}
	return 0;
}
