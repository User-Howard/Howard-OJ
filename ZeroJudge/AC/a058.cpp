#include<iostream>
using namespace std;


int main(void){
	int co,li[3]={0};
	scanf("%d",&co);
	while(co--){
		int a;
		scanf("%d",&a);
		li[a%3]++;
	}
	printf("%d %d %d",li[0],li[1],li[2]);
	return 0;
}
