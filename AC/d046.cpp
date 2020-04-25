#include<iostream>
using namespace std;


int main(void){
	int a,b,sum=0;
	scanf("%d",&a);
	while(a--){
		scanf("%d",&b);
		if(b<=10){
			sum+=1;
		}
	}
	printf("%d",sum);
	return 0;
}
