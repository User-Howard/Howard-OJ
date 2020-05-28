#include<stdio.h>

int main(){
	
	long long int r,a;
	long long int out;
	int temp;
	
	scanf("%lld%lld",&r,&a);
	
	if(r==a){
		a-=3;		
	}
	out=r-a;
	if(a>out){
		temp=a;
		a=out;
		out=temp;
		
	}
	
	printf("%lld+%lld=%lld\n",a,out,r); 
	
	
	return 0;
}
